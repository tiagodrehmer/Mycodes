/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Locadora;

import PacCarro.Carro;
import PacClientes.*;

/**
 *
 * @author leonardo
 */
public interface IRepositorio {
    
    /**
     * 
     * @param codigo
     * @return 
     */
    public Cliente percorreCadastroFisico(String busca);
   
    public Cliente percorreCadastroJuridico(String busca);
    
    public boolean addClienteFisico(ClienteFisico novo_cliente);
    
    public boolean addClienteJuridico(ClienteJuridico novo_cliente);
    
    public Carro percorreCarro(int chassi);
    
    public boolean addCarro(Carro novo_carro);
    
    
    
}
