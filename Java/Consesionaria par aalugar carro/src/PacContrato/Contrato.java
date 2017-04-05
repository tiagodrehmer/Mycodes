/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package PacContrato;
import PacCarro.Carro;
import PacClientes.Cliente;


/**
 *
 * @author leonardo
 */
public class Contrato {
    
    private String descricao;
    private int periodo;
    public Cliente cliente;
    public Carro carro;
    private String data;
    private static int codigoGeral = 1;
    private int codigo;
    

    public Contrato(String descricao, int periodo, Cliente cliente, Carro carro, String data){
        this.carro = carro;
        this.cliente = cliente;
        this.descricao = descricao;
        this.periodo = periodo;
        this.data = data;
        this.codigo = codigoGeral;
        codigoGeral++;
    }
    
    public Contrato(){
        
    }
    
    public Contrato(String descricao, int periodo, Cliente cliente, Carro carro, String data, int codigo){
        this.carro = carro;
        this.cliente = cliente;
        this.descricao = descricao;
        this.periodo = periodo;
        this.data = data;
        this.codigo = codigo;
        codigoGeral = codigo + 1;
    }
    
    public int getCodigo(){
        return codigo;
    }
    
    public Cliente getCliente(){
        return cliente;
    }
    
    public Carro getCarro(){
        return carro;
    }
    
    public String getDescricao(){
        return descricao;
    }
    
    public void setDescricao(String descricao){
        this.descricao = descricao;
    }
    
    
    public int getPeriodo(){
        return periodo;
    }
    
    public void setPeriodo(int periodo){
        this.periodo = periodo;
    }
    
    public String getData(){
        return data;
    }
    
    @Override
    public String toString(){

        return (cliente.toString() + "\n" + carro.toString() + "\n\nContrato\n" + "Descricao:" + descricao + "\nPeriodo:" + periodo + "\nData:" + data); 
    }
    

}


