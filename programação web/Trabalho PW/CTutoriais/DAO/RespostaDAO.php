<?php

class RespostaDAO extends DAO {

    /**
     * Método para inserir uma nova resposta 
     * @param $respostaVO RespostaVO objeto contendo os dados da resposta escrita pelo usuário
     */
    function insert($respostaVO) {
        $connect = $this->getConnect();
        $sql = "INSERT INTO forum.resposta(userID, questaoID, resposta, codigoresposta, dataresposta)
                    VALUES ('" . $respostaVO->getUserID() . "',
                            '" . $respostaVO->getQuestaoID() . "',
                            '" . $respostaVO->getResposta() . "',
                            '" . $respostaVO->getCodigo() . "',
                            now() ) ";
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
    


    /**
     * Método para selecionar todas as respostas de uma questão 
     * @param $questaoID int id da questão que se quer obter as respostas
     */
    function selectRespostasByQuestao($questaoID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "SELECT resposta.respostaID, resposta.questaoID, resposta.userID, resposta.dataresposta, resposta.resposta, resposta.codigoresposta, usuario.nome"
                . " FROM resposta, usuario"
                . " WHERE questaoID = $questaoID and resposta.userID = usuario.userID;";
        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            // informações de cada linha
            while ($row = $result->fetch_assoc()) {
                $resposta = new RespostaVO($row["respostaID"], $row["questaoID"], $row["userID"], $row["dataresposta"], $row["resposta"], $row["nome"], $row["codigoresposta"]);
                $respostas[] = $resposta;
            }
            $connect->close();
            return $respostas;
        }
    }

    function selectRespostaByID($respostaID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "SELECT * FROM forum.resposta WHERE respostaID = $respostaID;";
        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            // informações de cada linha
            while ($row = $result->fetch_assoc()) {
                $resposta = new RespostaVO($row["respostaID"], $row["questaoID"], $row["userID"], $row["dataresposta"], $row["resposta"]);
                $connect->close();
                return $respostas;
            }
        }
    }

    /**
     * Método para decobrir a quantidade de respostas que uma determinada questão tem
     * @param type $questaoID id da questão
     * @return int quantidade de respostas
     */
    function selectNumeroRespostas($questaoID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "SELECT COUNT(*) as total FROM forum.resposta WHERE questaoID = $questaoID;";
        $result = $connect->query($sql);
        //$num = mysql_fetch_assoc($result);
        if ($result->num_rows > 0) {
            // informações de cada linha
            while ($row = $result->fetch_assoc()) {
                $num = $row['total'];
                $connect->close();
                return $num;
            }
        } else {
            $connect->close();
            return 0;
        }
    }

    /**
     *  Método para remover uma questão do banco
     * @param type $respostaID id da resposta e ser removida
     * @return boolean true se foi excluida com sucesso senao false
     */
    function delete($respostaID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }

        $sql = "Delete from resposta WHERE respostaID = " . $respostaID . ";";
        if ($connect->query($sql) === TRUE) {
            //deu certo
            $delete = true;
        } else {
            //nao deu
            $delete = false;
        }
        $connect->close();
        return $delete;
    }

    /**
     * Método para atualizar uma resposta editada
     * @param type $respostaVO objeto com os dados a serem atualizados
     */
    public function update($respostaVO) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "UPDATE resposta
                SET resposta.resposta = '" . $respostaVO->getResposta() . "',
                resposta.codigoresposta = '" . $respostaVO->getCodigo() . "'
                WHERE resposta.respostaID = " . $respostaVO->getRespostaID() . ";";

        if ($connect->query($sql) === TRUE) {
            
        } else {
            
        }
        $connect->close();
    }

}
