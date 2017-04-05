<?php

require '/../vendor/autoload.php';

class UsuarioDAO extends DAO {
    /*
     * Método para verificar se existe alguma ocorrência de acordo com um comando sql
     * @param $sql string consulta a ser executada no banco
     * @return TRUE se encontrar alguma ocorrência e FALSE se não encontrar
     */

    public function existeNoBanco($sql) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }

        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            //se encontrou algo com a query executada
            $connect->close();
            return TRUE;
        } else {
            //se NÃO encontrou algo com a query executada
            $connect->close();
            return FALSE;
        }
    }

    /*
     * Método para buscar um usuário no banco pelo seu login email ou username e senha
     * @param $username string username ou email do usuário
     * @param $senha string senha do usuario
     * @return TRUE se os dados informados nos parâmetros existirem e combinarem
     * senão retorna FALSE 
     */

    public function selectByLogin($username, $senha) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "SELECT userID,nome,senha,email,username FROM forum.usuario"
                . " WHERE username = '$username' and senha = MD5('$senha');";
        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            // output data of each row
            while ($row = $result->fetch_assoc()) {
                $user = new UsuarioVO($row["nome"], $row["senha"], $row["email"], $row["username"], $row["userID"]);
                $connect->close();
                return $user;
            }
        } else {
            $sql = "SELECT userID,nome,senha, email,username FROM forum.usuario"
                    . " WHERE email = '$username' and senha = MD5('$senha');";
            $result = $connect->query($sql);
            if ($result->num_rows > 0) {
                // output data of each row
                while ($row = $result->fetch_assoc()) {
                    $user = new UsuarioVO($row["nome"], $row["senha"], $row["email"], $row["username"], $row["userID"]);
                    $connect->close();
                    return $user;
                }
            } else {
                $connect->close();
                return FALSE;
            }
        }
        $connect->close();
    }

    /*
     * Método para inserir um novo usuário no banco de dados
     *  @param $userVO usuarioVO usuario com as informações a serem inseridas
     */

    public function insert($userVO) {
        $connect = $this->getConnect();
        $sql = "INSERT INTO forum.usuario(username, email, senha, nome)
                    VALUES ('" . $userVO->getUsername() . "',
                            '" . $userVO->getEmail() . "',
                            MD5(" . "'" . $userVO->getSenha() . "'),
                            '" . $userVO->getNome() . "') ";




        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }

        if ($connect->query($sql) === TRUE) {
            //se conseguiu realizar a inserção no banco
        } else {
            //se a inserção no banco falhou
        }
        $connect->close();
    }

    /*
     * Método para atualizar os dados de um usuário
     *  @param $userVO usuarioVO usuario com as novas informações a serem atualizadas
     *  @param $username string username do usuario para encontrar a ocorrência no banco
     */

    public function update($userVO) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "UPDATE usuario
                SET usuario.username = '" . $userVO->getUsername() . "',
                    usuario.email = '" . $userVO->getEmail() . "',
                    usuario.nome = '" . $userVO->getNome() . "',
                    usuario.senha = '" . $userVO->getSenha() . "' 
                WHERE usuario.userID = " . $userVO->getID() . ";";

        if ($connect->query($sql) === TRUE) {
            
        } else {
            
        }
        $connect->close();
    }

    /*
     * Método para remover um usuário do banco de dados
     *  @param $userID id do usuário a ser removido do banco
     */

    public function delete($userID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "Delete from questao WHERE userID = " . $userID . ";";
        $connect->query($sql);
        $sql = "Delete from resposta WHERE userID = " . $userID . ";";
        $connect->query($sql);

        $sql = "Delete from usuario WHERE userID = " . $userID . ";";
        if ($connect->query($sql) === TRUE) {
            
        } else {
            
        }
        $connect->close();
    }

}
