/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Main;

import Locadora.Repositorio;
import PacCarro.Carro;
import PacClientes.*;
import PacContrato.Contrato;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;
import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author leonardo
 */
public class main {
    
    static Repositorio rep = new Repositorio();
    Scanner ler = new Scanner(System.in);
    
    
    /*
    public void menu()throws Exception{
        rep.lerArquivo("Cliente.csv");
        rep.lerArquivo("Carro.csv");
        rep.lerArquivo("Contrato.csv");
        int opcao = 10;
        
        
        
        do{
            System.out.println("1 - Alugar veiculo");
            System.out.println("2 - Adicionar carro");
            System.out.println("3 - Remover carro");
            System.out.println("4 - Remover cliente");
            System.out.println("5 - Pesquisar contrato");
            System.out.println("0 - Sair");
            opcao = ler.nextInt();
            switch(opcao){
                
                case 0:
                    rep.escreverArquivo("Cliente.csv");
                    rep.escreverArquivo("Contrato.csv");
                    rep.escreverArquivo("Carro.csv");
                    System.exit(1);
                
                case 1:
                    System.out.println("Já possui cadastro? 1 - SIM     2 - NAO");
                    opcao = ler.nextInt();
                    switch(opcao){
                        
                        case 1:
                            System.out.println("Digite seu código de cliente:");
                            Cliente cliente = rep.percorreCadastro(ler.nextInt());
                            
                            if(cliente == null){
                                System.out.println("Cliente não encontrado");
                                break;
                            }
                            
                            System.out.println("Digite o chassi do carro:");
                            
                            Carro carro = rep.percorreCarro(ler.nextInt());
                            
                            if(carro == null){
                                System.out.println("Carro não encontrado");
                                break;
                            }
                            
                            Locale locale = new Locale("pt","BR");
                            GregorianCalendar calendar = new GregorianCalendar();
                            SimpleDateFormat formatador = new SimpleDateFormat("dd' de 'MMMMM' de 'yyyy' - 'HH':'mm'h'",locale);

                            criarContrato(cliente, carro, (formatador.format(calendar.getTime())));
                            
                            break;
                        case 2:
                            String nome;
                            String end;
                            int fone;
                            
                            do{
                                System.out.println("Tipo de cliente? 1 - Fisico     2 - Juridico");
                                opcao = ler.nextInt();
                                ler.nextLine();

                                switch(opcao){

                                    case 1:
                                        System.out.println("Nome:");
                                        nome = ler.nextLine();

                                        System.out.println("Endereco(Rua-numero):");
                                        end = ler.nextLine();
                                        
                                        System.out.println("Telefone para contato");
                                        fone = ler.nextInt();
                                        ler.nextLine();
                                        cadastroFisico(nome, end, fone);
                                        break;

                                    case 2:
                                        System.out.println("Nome:");
                                        nome = ler.next().trim();

                                        System.out.println("Endereco(Rua-numero):");
                                        end = ler.next().trim();
                                        
                                        System.out.println("Telefone para contato");
                                        fone = ler.nextInt();
                                        
                                        
                                        cadastroJuridico(nome, end, fone);
                                        break;
                                    default:
                                        System.out.println("Comando invalido");
                                        break;
                                }
                            }while(opcao != 1 && opcao != 2);
                            
                            break;
                            
                        default:
                            System.out.println("Opcao invalida");
                            break;
                            
                    }
                break;
                    
                case 2:
                    cadastrarCarro();
                    break;
                
                case 3:
                    Carro aux = rep.percorreCarro(ler.nextInt());
                    if(aux != null){
                        System.out.println(aux.toString()); 
                    }
                    break;
                    
                case 4:
                    System.out.println("Codigo do cliente");
                    if(rep.delCliente(ler.nextInt())){
                        System.out.println("Cliente removido");
                    }else{
                        System.out.println("Cliente não encontrado");
                    }
                    break;
                    
                case 5:
                    Contrato busca = new Contrato();
                    System.out.println("Codigo do contrato:");
                    busca = rep.percorreContrato(ler.nextInt());
                
                    if(busca != null){
                        System.out.println(busca.toString()); 
                    }else{
                        System.out.println("Contrado não encontrado");
                    }
                    break;
                        
                default:
                    System.out.println("Opcao invalida");
                    break;
            }
            
        }while(opcao != 0);
    }
    
    public void criarContrato(Cliente cliente, Carro carro, String data){
        
        int periodo;
        String descricao;
        
        System.out.println("Descricao do uso do veiculo:");
        descricao = ler.next();
        
        System.out.println("Periodo do aluguel(dias):");
        periodo = ler.nextInt();
        
        Contrato novo_contrato = new Contrato(descricao, periodo, cliente, carro, data);
        
        if(rep.addContrato(novo_contrato)){
            System.out.println("Contrato concluido com sucesso!\nCodigo do contrato:" + novo_contrato.getCodigo());
        }else{
            System.out.println("Contrato não concluido");
        }
        
    }
    
    public void cadastroFisico(String nome, String end, int fone){

        String cpf;
        int habilitacao;
       
                
        System.out.println("Cpf:");
        cpf = ler.next().trim();
        
        System.out.println("Numero da habilitacao:");
        habilitacao = ler.nextInt();
        

        
        ClienteFisico novo_cliente = new ClienteFisico(nome, end, cpf, habilitacao, fone);
        
        if(rep.addCliente(novo_cliente)){
            System.out.println("Cadastro concluido com sucesso!\nSeu codigo de cliente é:" + novo_cliente.getCodigo());
        }else{
            System.out.println("Cadastro não concluido");
        }
        
    }
    
    public void cadastroJuridico(String nome, String end, int fone){
        String cnpj;
        String proprietario;
        
        System.out.println("CNPJ:");
        cnpj = ler.next().trim();
        
        System.out.println("Proprietario:");
        proprietario = ler.next().trim();
        
        ClienteJuridico novo_cliente = new ClienteJuridico(nome, end, cnpj, proprietario, fone);
        
        if(rep.addCliente(novo_cliente)){
            System.out.println("Cadastro concluido com sucesso!\nSeu codigo de cliente é:" + novo_cliente.getCodigo());
        }
    }
    
    public void cadastrarCarro(){
        int chassi;
        String modelo;
        int ano;
        String placa;
        Float km;
        
        System.out.println("Chassi:");
        chassi = ler.nextInt();
        //verifica
        
        System.out.println("Modelo:");
        modelo = ler.next().trim();
        
        System.out.println("Ano:");
        ano = ler.nextInt();
        
        System.out.println("Placa:");
        placa = ler.next().trim();
        
        System.out.println("Kilometragem atual do veiculo");
        km = ler.nextFloat();
        
        Carro novo_carro = new Carro(chassi, modelo, ano, placa, km);
        
        if(rep.addCarro(novo_carro)){
            System.out.println("Carro cadastrado com sucesso");
        }else{
            System.out.println("Carro não cadastrado\n");
        }
    }
    */
    public static void main(String[] args)throws Exception{
        //main executar = new main();
        //executar.menu();
        new FrameMenu().setVisible(true);
    }
}
