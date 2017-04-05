/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import Adiciona.Adiciona_Contrato;
import Locadora.Repositorio;
import static Main.FrameMenu.rep;
import PacClientes.Cliente;
import java.text.ParseException;
import javax.swing.JOptionPane;
import javax.swing.text.MaskFormatter;

/**
 *
 * @author leonardo
 */
public class BuscaCliente extends javax.swing.JFrame {

    static Repositorio rep = new Repositorio();

    /**
     * Creates new form BuscaCliente
     */
    public BuscaCliente(Repositorio rep) throws ParseException {
        this.rep = rep;
        initComponents();
        MaskFormatter formatoCnpj, formatoCpf;

        formatoCnpj = new javax.swing.text.MaskFormatter("##.###.###/####-##");
        formatoCnpj.setValidCharacters("0123456789");
        formatoCnpj.setPlaceholderCharacter('0');
        formatoCnpj.install(BuscaJuridico);

        formatoCpf = new javax.swing.text.MaskFormatter("###.###.###-##");
        formatoCpf.setValidCharacters("0123456789");
        formatoCpf.setPlaceholderCharacter('0');
        formatoCpf.install(BuscaFisico);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BFisico = new javax.swing.JButton();
        BJuridico = new javax.swing.JButton();
        Cancelar = new javax.swing.JButton();
        BuscaFisico = new javax.swing.JFormattedTextField();
        BuscaJuridico = new javax.swing.JFormattedTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        BFisico.setText("Fisico");
        BFisico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BFisicoActionPerformed(evt);
            }
        });

        BJuridico.setText("Juridico");
        BJuridico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BJuridicoActionPerformed(evt);
            }
        });

        Cancelar.setText("Cancelar");
        Cancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CancelarActionPerformed(evt);
            }
        });

        jLabel1.setText("CPF");

        jLabel2.setText("CNPJ");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(Cancelar, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(134, 134, 134))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(BFisico, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(BuscaFisico, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(BJuridico, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(BuscaJuridico))))
                .addContainerGap(50, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BFisico)
                    .addComponent(BuscaFisico, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BJuridico)
                    .addComponent(BuscaJuridico, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(Cancelar)
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void BFisicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BFisicoActionPerformed
        String cod = BuscaFisico.getText();
        Cliente cli = rep.percorreCadastroFisico(cod);
        if (cli != null) {
            new Adiciona_Contrato(cli, rep).setVisible(true);
        } else {
            JOptionPane.showMessageDialog(rootPane, "Cliente não encontrado");
            //new FrameMenu(rep).setVisible(true);
        }

    }//GEN-LAST:event_BFisicoActionPerformed

    private void BJuridicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BJuridicoActionPerformed
        String cod = BuscaJuridico.getText();
        Cliente cli = rep.percorreCadastroJuridico(cod);
        if (cli != null) {
            new Adiciona_Contrato(cli, rep).setVisible(true);
        } else {
            JOptionPane.showMessageDialog(rootPane, "Cliente não encontrado");
            //new FrameMenu(rep).setVisible(true);
        }

        this.dispose();
    }//GEN-LAST:event_BJuridicoActionPerformed

    private void CancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CancelarActionPerformed
        this.dispose();
        new FrameMenu(rep).setVisible(true);
    }//GEN-LAST:event_CancelarActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BFisico;
    private javax.swing.JButton BJuridico;
    private javax.swing.JFormattedTextField BuscaFisico;
    private javax.swing.JFormattedTextField BuscaJuridico;
    private javax.swing.JButton Cancelar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    // End of variables declaration//GEN-END:variables
}