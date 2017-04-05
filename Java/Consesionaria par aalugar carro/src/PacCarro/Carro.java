/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package PacCarro;

/**
 *
 * @author leonardo
 */
public class Carro {
    
    private int chassi;
    private String modelo;
    private int ano;
    private String placa;
    private float km_atual;
    
    public Carro(int chassi, String modelo, int ano, String placa, float km){
        this.ano = ano;
        this.chassi = chassi;
        this.modelo = modelo;
        this.placa = placa;
        this.km_atual = km;
    }
    
    public int getChassi(){
        return chassi;
    }
    
    public void setChassi(int chassi){
        this.chassi = chassi;
    }
    
    
    public String getModelo(){
        return modelo;
    }
    
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    
    public int getAno(){
        return ano;
    }
    
    public void setAno(int ano){
        this.ano = ano;
    }
    
    public String getPlaca(){
        return placa;
    }
    
    public void setPlaca(String placa){
        this.placa = placa;
    }
    
    public float getKm_atual(){
        return km_atual;
    }
    
    public void setKm_autal(float km){
        this.km_atual = km;
    }
    
    
    @Override
    public String toString(){
        return ("\nCarro:\nChassi:" + chassi + "\nModelo:" + modelo + "\nAno:" + ano + "\nPlaca:" + placa + "\nKm atual:" + km_atual);
    }
}

  
