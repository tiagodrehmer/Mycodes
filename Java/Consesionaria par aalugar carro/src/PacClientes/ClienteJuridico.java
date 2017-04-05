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
public class ClienteJuridico extends Cliente{
    
    private String cnpj;
    private String proprietario;
    
    
    
    public ClienteJuridico(String nome, String end, String fone, String cnpj, String proprietario) {
        super(nome, end, fone);
        this.proprietario = proprietario;
        this.cnpj = cnpj;
    }
    
    
    public String getCnpj(){
        return cnpj;
    }
    
    public void setCnpj(String cnpj){
        this.cnpj = cnpj;
    }
    
    public String getProprietario(){
        return proprietario;
    }
    
    public void setProprietario(String proprietario){
        this.proprietario = proprietario;
    }
    
    @Override
    public String toString(){
        return (super.toString() + "\nCNPJ:" + cnpj + "\nProprietario:" + proprietario);
    }
}
