<?php

require '/../vendor/autoload.php';

class QuestaoDAO extends DAO {

    /**
     * Método para inserir uma nova questão no banco
     * @param $questaoVO questaoVO objeto contendo os dados da questão a ser inserida 
     */
    function insert($questaoVO) {
        $connect = $this->getConnect();
        $sql = "INSERT INTO forum.questao(userID, titulo, descricao, codigodescricao, dataquestao)
                    VALUES ('" . $questaoVO->getUserID() . "',
                            '" . $questaoVO->getTitulo() . "',
                            '" . $questaoVO->getDescricao() . "',
                            '" . $questaoVO->getCodigo() . "',
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
     * Método para buscar todas as questões existentes no banco
     * @return array de QuestaoVO
     */
    function selectAll() {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "select questao.questaoID, questao.userID, usuario.nome, questao.titulo, questao.descricao, questao.dataquestao, questao.codigodescricao
                from questao, usuario
                where questao.questaoID != 0 and  questao.userID = usuario.userID
                ORDER BY dataquestao DESC;";
        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            // informações de cada linha
            while ($row = $result->fetch_assoc()) {
                $questao = new QuestaoVO($row["titulo"], $row["descricao"], $row["dataquestao"], $row["questaoID"], $row["userID"],$row["nome"],$row["codigodescricao"]);
                //adiciona cada linha em um array de questoes
                $questoes[] = $questao;
            }
            $connect->close();
            return $questoes;
        }
    }

    function selectByID($questaoID) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "SELECT questao.questaoID, questao.userID, usuario.nome, questao.titulo, questao.descricao, questao.dataquestao, questao.codigodescricao"
                . " FROM questao, usuario"
                . " WHERE questaoID = $questaoID and questao.userID = usuario.userID;";
        $result = $connect->query($sql);

        if ($result->num_rows > 0) {
            // informações da questao
            while ($row = $result->fetch_assoc()) {
                $questao = new QuestaoVO($row["titulo"], $row["descricao"], $row["dataquestao"], $row["questaoID"], $row["userID"], $row["nome"], $row["codigodescricao"]);
            }
            $connect->close();
            return $questao;
        }
        else{
            return false;
        }
    }
    
    /**
     * Método para atualizar uma questão que foi editada no banco
     * @param type $questaoVO objeto com informações atualizadas da questão
     */
    
    function update($questaoVO) {
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "UPDATE questao
                SET questao.titulo = '" . $questaoVO->getTitulo() . "',
                    questao.codigodescricao = '" . $questaoVO->getCodigo() . "',
                    questao.descricao = '" . $questaoVO->getDescricao() . "'
                WHERE questao.questaoID = " . $questaoVO->getQuestaoID() . ";";

        if ($connect->query($sql) === TRUE) {
            
        } else {
            
        }
        $connect->close();
    }
    
    function delete ($questaoID){
        $connect = $this->getConnect();
        if ($connect->connect_error) {
            die("Connection failed: " . $connect->connect_error);
        }
        $sql = "DELETE FROM resposta WHERE questaoID =" . $questaoID . ";";
        $connect->query($sql);
        $sql = "DELETE FROM questao WHERE questaoID = " . $questaoID . ";";
        $connect->query($sql);
        $connect->close();
    }

}
