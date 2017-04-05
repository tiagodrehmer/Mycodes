/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import Locadora.Repositorio;
import java.text.ParseException;
import javax.swing.JOptionPane;
import javax.swing.text.MaskFormatter;

/**
 *
 * @author leonardo
 */
public class Remover extends javax.swing.JFrame {

    public Repositorio rep = new Repositorio();

    /**
     * Creates new form RemoverCliente
     *
     * @param rep
     * @throws java.text.ParseException
     */
    public Remover(Repositorio rep) throws ParseException {
        this.rep = rep;
        initComponents();
        MaskFormatter formatoCnpj, formatoCpf;

        formatoCnpj = new javax.swing.text.MaskFormatter("##.###.###/####-##");
        formatoCnpj.setValidCharacters("0123456789");
        formatoCnpj.install(DelJuridico);

        formatoCpf = new javax.swing.text.MaskFormatter("###.###.###-##");
        formatoCpf.setValidCharacters("0123456789");
        formatoCpf.install(DelFisico);

    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BTN_Fisico = new javax.swing.JButton();
        BTN_Juridico = new javax.swing.JButton();
        Cancelar = new javax.swing.JButton();
        DelFisico = new javax.swing.JFormattedTextField();
        DelJuridico = new javax.swing.JFormattedTextField();
        BTN_Contrato = new javax.swing.JButton();
        BTN_Carro = new javax.swing.JButton();
        DelCarro = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        DelContrato = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        BTN_Fisico.setText("Fisico");
        BTN_Fisico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BTN_FisicoActionPerformed(evt);
            }
        });

        BTN_Juridico.setText("Juridico");
        BTN_Juridico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BTN_JuridicoActionPerformed(evt);
            }
        });

        Cancelar.setText("Cancelar");
        Cancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CancelarActionPerformed(evt);
            }
        });

        BTN_Contrato.setText("Contrato");
        BTN_Contrato.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BTN_ContratoActionPerformed(evt);
            }
        });

        BTN_Carro.setText("Carro");
        BTN_Carro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BTN_CarroActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Ubuntu", 0, 20)); // NOI18N
        jLabel1.setText("Remover:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(Cancelar, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jLabel1)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(BTN_Fisico, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(DelFisico, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(BTN_Juridico, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(BTN_Contrato, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(BTN_Carro, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(DelJuridico)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(DelCarro, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(0, 0, Short.MAX_VALUE))
                                    .addComponent(DelContrato))))))
                .addContainerGap(52, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BTN_Fisico)
                    .addComponent(DelFisico, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(15, 15, 15)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BTN_Juridico)
                    .addComponent(DelJuridico, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BTN_Contrato)
                    .addComponent(DelContrato, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BTN_Carro)
                    .addComponent(DelCarro, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Cancelar)
                .addContainerGap(20, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void BTN_FisicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BTN_FisicoActionPerformed

        if (rep.delClienteFisico(DelFisico.getText())) {
            JOptionPane.showMessageDialog(rootPane, "Cliente removido com sucesso!");
        } else {
            JOptionPane.showMessageDialog(rootPane, "Não foi possivel remover o cliente");
        }
    }//GEN-LAST:event_BTN_FisicoActionPerformed

    private void BTN_JuridicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BTN_JuridicoActionPerformed

        if (rep.delClienteJuridico(DelJuridico.getText())) {
            JOptionPane.showMessageDialog(rootPane, "Cliente removido com sucesso!");
        } else {
            JOptionPane.showMessageDialog(rootPane, "Não foi possivel remover o cliente");
        }
    }//GEN-LAST:event_BTN_JuridicoActionPerformed

    private void CancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CancelarActionPerformed
        this.dispose();
        new FrameMenu(rep).setVisible(true);
    }//GEN-LAST:event_CancelarActionPerformed

    private void BTN_ContratoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BTN_ContratoActionPerformed

        if (rep.delContrato(Integer.parseInt(DelContrato.getText()))) {
            JOptionPane.showMessageDialog(rootPane, "Contrato removido com sucesso!");
        } else {
            JOptionPane.showMessageDialog(rootPane, "Não foi possivel remover o contrato");
        }
    }//GEN-LAST:event_BTN_ContratoActionPerformed

    private void BTN_CarroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BTN_CarroActionPerformed

        if (rep.delCarro(Integer.parseInt(DelCarro.getText()))) {
            JOptionPane.showMessageDialog(rootPane, "Carro removido com sucesso!");
        } else {
            JOptionPane.showMessageDialog(rootPane, "Não foi possivel remover o carro");
        }
    }//GEN-LAST:event_BTN_CarroActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BTN_Carro;
    private javax.swing.JButton BTN_Contrato;
    private javax.swing.JButton BTN_Fisico;
    private javax.swing.JButton BTN_Juridico;
    private javax.swing.JButton Cancelar;
    private javax.swing.JTextField DelCarro;
    private javax.swing.JTextField DelContrato;
    private javax.swing.JFormattedTextField DelFisico;
    private javax.swing.JFormattedTextField DelJuridico;
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables
}