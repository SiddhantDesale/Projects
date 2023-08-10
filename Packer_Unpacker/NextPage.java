// NextPage.java

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class NextPage extends Template implements ActionListener
{
    JLabel label;
    JButton pack, unpack;

    NextPage(String value)
    {
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        label = new JLabel("Welcome: "+value);
        Dimension size = label.getPreferredSize();
        label.setBounds(10,40, size.width + 50, size.height + 50);
        label.setFont(new Font("Times",Font.BOLD,15));
        label.setForeground(Color.BLACK);

        pack = new JButton("Pack Files");
        Dimension bsize = pack.getPreferredSize();
        pack.setBounds(100,100, bsize.width, bsize.height);
        pack.addActionListener(this);

        unpack = new JButton("Unpack Files");
        Dimension b2size = unpack.getPreferredSize();
        unpack.setBounds(300,100, b2size.width + 20, b2size.height);
        unpack.addActionListener(this);

        _header.add(label);
        _content.add(pack);
        _content.add(unpack);

        ClockHome();
        this.setSize(500,500);
        this.setResizable(false);
        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent ae)
    {
        if(ae.getSource() == exit)
        {
            this.setVisible(false);
            System.exit(0);
        }
        if(ae.getSource() == minimize)
        {
            this.setState(this.ICONIFIED);
        }
        if(ae.getSource() == pack)
        {
            this.setVisible(false);
            try
            {
                SiddhantPackFront obj = new SiddhantPackFront();
            }
            catch(Exception e){}
        }
        if(ae.getSource() == unpack)
        {
            this.setVisible(false);
            SiddhantUnpackFront obj = new SiddhantUnpackFront();
        }
    }
}