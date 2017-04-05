/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Editar;

import Locadora.Repositorio;
import Main.FrameMenu;

/**
 *
 * @author leonardo
 */
public class SelecionarTipo extends javax.swing.JFrame {
    static Repositorio rep = new Repositorio();
    /**
     * Creates new form SelecionarTipo
     */
    public SelecionarTipo(Repositorio rep) {
        this.rep = rep;
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Selec_Fisico = new javax.swing.JButton();
        Selec_Juridico = new javax.swing.JButton();
        Selec_carro = new javax.swing.JButton();
        Cancelar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Selec_Fisico.setText("Cliente Fisico");
        Selec_Fisico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Selec_FisicoActionPerformed(evt);
            }
        });

        Selec_Juridico.setText("Cliente Juridico");
        Selec_Juridico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Selec_JuridicoActionPerformed(evt);
            }
        });

        Selec_carro.setText("Carro");
        Selec_carro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Selec_carroActionPerformed(evt);
            }
        });

        Cancelar.setText("Cancelar");
        Cancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CancelarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(Selec_Fisico, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(Selec_carro, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(Selec_Juridico, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(Cancelar, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(45, 45, 45)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Selec_Fisico)
                    .addComponent(Selec_carro)
                    .addComponent(Selec_Juridico))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 35, Short.MAX_VALUE)
                .addComponent(Cancelar)
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void Selec_FisicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Selec_FisicoActionPerformed
        try {
            this.dispose();
            new Edit_Fisico(rep).setVisible(true);
        }catch (Exception e){
            
        }        
    }//GEN-LAST:event_Selec_FisicoActionPerformed

    private void Selec_carroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Selec_carroActionPerformed
        try {
            this.dispose();
            new Edit_Carro(rep).setVisible(true);
        }catch (Exception e){
            
        }
    }//GEN-LAST:event_Selec_carroActionPerformed

    private void CancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CancelarActionPerformed
        this.dispose();
        new FrameMenu(rep).setVisible(true);
    }//GEN-LAST:event_CancelarActionPerformed

    private void Selec_JuridicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Selec_JuridicoActionPerformed
        try {
            this.dispose();
            new Edit_Juridico(rep).setVisible(true);
        }catch (Exception e){
            
        }
    }//GEN-LAST:event_Selec_JuridicoActionPerformed

 

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Cancelar;
    private javax.swing.JButton Selec_Fisico;
    private javax.swing.JButton Selec_Juridico;
    private javax.swing.JButton Selec_carro;
    // End of variables declaration//GEN-END:variables
}
