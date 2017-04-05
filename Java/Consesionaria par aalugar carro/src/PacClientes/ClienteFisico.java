/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package PacClientes;

/**
 *
 * @author leonardo
 */
public class ClienteFisico extends Cliente {
    
    private String cpf;
    private String numero_habilitacao;

    public ClienteFisico(String nome, String end, String fone, String cpf, String n_hab) {
        super(nome, end, fone);
        this.cpf = cpf;
        this.numero_habilitacao = n_hab;
        
    }
    
    public String getCpf(){
        return cpf;
    }
    
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    
    
    public String getN_hab(){
        return numero_habilitacao;
    }
    
    public void setN_hab(String n_hab){
        this.numero_habilitacao = n_hab;
    }
    
    @Override
    public String toString(){
        
        return (super.toString() + "\nCPF:" + cpf + "\nHabilitação:" + numero_habilitacao);
    }
}
