package PacClientes;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author leonardo
 */
public abstract class Cliente {
    
    protected String nome;
    protected String endereco;
    protected String fone;

    public Cliente(String nome, String end, String fone){
        this.nome = nome;
        this.endereco = end;
        this.fone = fone;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    
    public String getEnd(){
        return endereco;
    }
    
    public void setEnd(String end){
        this.endereco = end;
    }
    
    
    public String getFone(){
        return fone;
    }
    
    public void setFone(String fone){
        this.fone = fone;
    }
   
    @Override
    public String toString(){
        return ("Cliente:\nNome:" + nome + "\nEndereço:" + endereco + "\nFone:" + fone);
    }

}
