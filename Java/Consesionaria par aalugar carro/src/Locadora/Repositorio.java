/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Locadora;

import PacContrato.*;
import java.util.ArrayList;
import PacClientes.*;
import PacCarro.Carro;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import javax.crypto.ExemptionMechanismException;
import javax.swing.DefaultListModel;

/**
 *
 * @author leonardo
 */
public class Repositorio implements IRepositorio {

    ArrayList<ClienteFisico> cadastroFisico = new ArrayList();
    ArrayList<ClienteJuridico> cadastroJuridico = new ArrayList();
    ArrayList<Carro> automoveis = new ArrayList();
    ArrayList<Contrato> contratos = new ArrayList();

    public Contrato percorreContrato(int codigo) {

        for (Contrato percorre : contratos) {
            if (percorre.getCodigo() == codigo) {
                return percorre;
            }
        }
        return null;
    }

    public boolean addContrato(Contrato novo_contrato) {

        if (percorreContrato(novo_contrato.getCodigo()) == null) {
            contratos.add(novo_contrato);
            return true;
        }
        return false;
    }

    public boolean delContrato(int codigo) {
        Contrato deleta = percorreContrato(codigo);

        if (deleta != null) {
            contratos.remove(deleta);
            return true;
        }
        return false;
    }

    public Cliente percorreCadastroFisico(String busca) {

        for (ClienteFisico percorre : cadastroFisico) {
            if (percorre.getCpf().equals(busca)) {
                return percorre;
            }
        }
        return null;
    }

    public Cliente percorreCadastroJuridico(String busca) {

        for (ClienteJuridico percorre : cadastroJuridico) {
            if (percorre.getCnpj().equals(busca)) {
                return percorre;
            }
        }
        return null;
    }

    public boolean addClienteFisico(ClienteFisico novo_cliente) {

        if (percorreCadastroFisico(novo_cliente.getCpf()) == null) {
            cadastroFisico.add(novo_cliente);
            return true;
        }

        return false;
    }

    public boolean addClienteJuridico(ClienteJuridico novo_cliente) {

        if (percorreCadastroJuridico(novo_cliente.getCnpj()) == null) {
            cadastroJuridico.add(novo_cliente);
            return true;
        }

        return false;
    }

    public boolean delClienteFisico(String cpf) {
        Cliente deleta = percorreCadastroFisico(cpf);

        if (deleta != null) {
            cadastroFisico.remove(deleta);
            System.out.println("deletou " + cadastroFisico.size());
            return true;
        }
        return false;
    }

    public boolean delClienteJuridico(String cnpj) {
        Cliente deleta = percorreCadastroJuridico(cnpj);

        if (deleta != null) {
            cadastroJuridico.remove(deleta);
            return true;
        }
        return false;
    }

    public Carro percorreCarro(int chassi) {

        for (Carro percorre : automoveis) {
            if (percorre.getChassi() == chassi) {
                return percorre;
            }
        }
        return null;
    }

    public DefaultListModel listCarros() {
        DefaultListModel lista = new DefaultListModel();

        for (Carro car : automoveis) {
            lista.addElement(car.getChassi() + ";" + "Modelo: " + car.getModelo() + ", ano " + car.getAno());
        }

        return lista;

    }

    public boolean addCarro(Carro novo_carro) {

        if (percorreCarro(novo_carro.getChassi()) == null) {
            automoveis.add(novo_carro);
            return true;
        }

        return false;
    }

    public boolean delCarro(int chassi) {
        Carro deleta = percorreCarro(chassi);

        if (deleta != null) {
            automoveis.remove(deleta);
            return true;
        }
        return false;
    }

    public void lerArquivo(String arquivo) throws Exception {
        FileInputStream inFile;
        BufferedReader buffer;

        String[] info;
        String linha;

        if (arquivo.equals("Carro.csv")) {
            try {
                inFile = new FileInputStream(new File("Carro.csv"));
                buffer = new BufferedReader(new InputStreamReader(inFile, "UTF-8"));

                if (inFile == null) {
                    return;
                }

                while ((linha = buffer.readLine()) != null) {

                    info = linha.split(";");

                    if (info.length == 5) {
                        Carro novo_carro = new Carro(Integer.parseInt(info[0]),
                                info[1],
                                Integer.parseInt(info[2]),
                                info[3],
                                Float.parseFloat(info[4]));
                        addCarro(novo_carro);

                    }
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        } else if (arquivo.equals("ClienteFisico.csv")) {
            try {
                inFile = new FileInputStream(new File("ClienteFisico.csv"));
                buffer = new BufferedReader(new InputStreamReader(inFile, "UTF-8"));

                while ((linha = buffer.readLine()) != null) {

                    info = linha.split(";");
                    int tam = info.length;
                    if (tam == 5) {

                        ClienteFisico novo_cliente = new ClienteFisico(info[0],
                                info[1],
                                info[2],
                                info[3],
                                info[4]);
                        addClienteFisico(novo_cliente);

                    }
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

        } else if (arquivo.equals("ClienteJuridico.csv")) {

            try {
                inFile = new FileInputStream(new File("ClienteJuridico.csv"));
                buffer = new BufferedReader(new InputStreamReader(inFile, "UTF-8"));

                while ((linha = buffer.readLine()) != null) {

                    info = linha.split(";");
                    int tam = info.length;
                    if (tam == 5) {

                        ClienteJuridico novo_cliente = new ClienteJuridico(info[0],
                                info[1],
                                info[2],
                                info[3],
                                info[4]);
                        addClienteJuridico(novo_cliente);

                    }
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

        } else {

            try {

                inFile = new FileInputStream(new File("Contrato.csv"));
                buffer = new BufferedReader(new InputStreamReader(inFile, "UTF-8"));

                if (inFile == null) {
                    return;
                }

                while ((linha = buffer.readLine()) != null) {

                    info = linha.split(";");
                    Cliente cli;
                    if (info.length == 7) {
                        if (Integer.parseInt(info[6]) == 1) {
                            cli = percorreCadastroFisico(info[2]);
                        } else {
                            cli = percorreCadastroJuridico(info[2]);
                        }

                        Contrato novo_contrato = new Contrato(info[0],
                                Integer.parseInt(info[1]),
                                cli,
                                percorreCarro(Integer.parseInt(info[3])),
                                info[4],
                                Integer.parseInt(info[5]));

                        addContrato(novo_contrato);
                    }
                }

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public void escreverArquivo(String arquivo) throws Exception {
        FileOutputStream outFile;
        BufferedWriter buffer;

        if (arquivo.equals("Carro.csv")) {
            outFile = new FileOutputStream(new File("Carro.csv"));
            buffer = new BufferedWriter(new OutputStreamWriter(outFile, "UTF-8"));
            for (Carro car : automoveis) {
                buffer.write(car.getChassi() + ";");
                buffer.write(car.getModelo() + ";");
                buffer.write(car.getAno() + ";");
                buffer.write(car.getPlaca() + ";");
                buffer.write("" + car.getKm_atual() + ";");
                buffer.write("\n");
            }
            buffer.close();
            outFile.close();

        } else if (arquivo.equals("ClienteFisico.csv")) {
            outFile = new FileOutputStream(new File("ClienteFisico.csv"));
            buffer = new BufferedWriter(new OutputStreamWriter(outFile, "UTF-8"));

            for (ClienteFisico cli : cadastroFisico) {

                buffer.write(cli.getNome() + ";");
                buffer.write(cli.getEnd() + ";");
                buffer.write(cli.getFone() + ";");
                buffer.write(cli.getCpf() + ";");
                buffer.write(cli.getN_hab() + ";");
                buffer.write("\n");
            }
            buffer.close();
            outFile.close();
        } else if (arquivo.equals("ClienteJuridico.csv")) {

            outFile = new FileOutputStream(new File("ClienteJuridico.csv"));
            buffer = new BufferedWriter(new OutputStreamWriter(outFile, "UTF-8"));

            for (ClienteJuridico cli : cadastroJuridico) {
                buffer.write(cli.getNome() + ";");
                buffer.write(cli.getEnd() + ";");
                buffer.write(cli.getFone() + ";");
                buffer.write(cli.getCnpj() + ";");
                buffer.write(cli.getProprietario() + ";");
                buffer.write("\n");
            }
            buffer.close();
            outFile.close();

        } else {
            outFile = new FileOutputStream(new File("Contrato.csv"));
            buffer = new BufferedWriter(new OutputStreamWriter(outFile, "UTF-8"));
            Cliente cli;
            for (Contrato con : contratos) {
                cli = con.getCliente();

                if (cli instanceof ClienteFisico) {
                    ClienteFisico fis = (ClienteFisico) cli;

                    buffer.write(con.getDescricao() + ";");
                    buffer.write(con.getPeriodo() + ";");
                    buffer.write(fis.getCpf() + ";");
                    buffer.write(con.getCarro().getChassi() + ";");
                    buffer.write(con.getData() + ";");
                    buffer.write(con.getCodigo() + ";");
                    buffer.write("1;");
                    buffer.write("\n");

                } else {
                    ClienteJuridico jur = (ClienteJuridico) cli;

                    buffer.write(con.getDescricao() + ";");
                    buffer.write(con.getPeriodo() + ";");
                    buffer.write(jur.getCnpj() + ";");
                    buffer.write(con.getCarro().getChassi() + ";");
                    buffer.write(con.getData() + ";");
                    buffer.write(con.getCodigo() + ";");
                    buffer.write("0;");
                    buffer.write("\n");

                }

            }
            buffer.close();
            outFile.close();
        }

    }

}
