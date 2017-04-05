<?php
require '/../vendor/autoload.php';
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class DAO{
    
    private $host;
    private $username;
    private $password;
    private $database;

    function __construct() {
        $this->host = "localhost";
        $this->username = "ctutoriais";
        $this->password = "passwd";
        $this->database = "forum";
    }

    /*
     * cria uma nova conexão com o banco com as seguintes propriedades;
     *  host = "localhost";
     *  username = "ctutoriais";
     *  password = "passwd";
     *  database = "forum";
     */

    public function getConnect() {
        $connect = new mysqli($this->host, $this->username, $this->password, $this->database);
        return $connect;
    }
}