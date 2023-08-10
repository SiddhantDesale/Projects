// SiddhantUnpackFront.java

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class InvalidFileException extends Exception
{
    public InvalidFileException(String str)
    {
        super(str);
    }
}

public class SiddhantUnpackFront extends Template implements ActionListener
{
    JButton SUBMIT, PREVIOUS;
    JLabel label1,label2,title;
    final JTextField text1;

    public SiddhantUnpackFront()
    {
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        title = new JLabel("Unpacking Portal");
        Dimension size = title.getPreferredSize();
        title.setBounds(10,40, size.width + 50, size.height + 50);
        title.setFont(new Font("Times",Font.BOLD,15));
        title.setForeground(Color.black);

        label1 = new JLabel();
        label1.setText("File name");
        label1.setForeground(Color.white);
        label1.setBounds(100,100, size.width, size.height);

        text1 = new JTextField(15);
        Dimension tsize = text1.getPreferredSize();
        text1.setBounds(200,100, tsize.width, tsize.height);
        text1.setToolTipText("Enter name of directory ");

        SUBMIT = new JButton("Extract Here");
        Dimension bsize = SUBMIT.getPreferredSize();
        SUBMIT.setBounds(125,200, bsize.width, bsize.height);
        SUBMIT.addActionListener(this);

        PREVIOUS = new JButton("Previous");
        Dimension b2size = PREVIOUS.getPreferredSize();
        PREVIOUS.setBounds(250,200, b2size.width + 20, b2size.height);
        PREVIOUS.addActionListener(this);

        _header.add(title);
        _content.add(label1);
        _content.add(text1);
        _content.add(SUBMIT);
        _content.add(PREVIOUS);

        ClockHome();
        this.setSize(500,500);
        this.setResizable(false);
        this.setVisible(true);
        text1.requestFocusInWindow();
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
        if(ae.getSource() == SUBMIT)
        {
            try
            {
                SiddhantUnpack obj = new SiddhantUnpack(text1.getText());
                this.dispose();
                NextPage t = new NextPage("Siddhant");
            }
            catch(InvalidFileException obj)
            {
                this.setVisible(false);
                this.dispose();

                JOptionPane.showMessageDialog(this,"Invalid packed File","Error",JOptionPane.ERROR_MESSAGE);
                NextPage t = new NextPage("Siddhant");
            }
            catch(Exception e)
            {}
        }
        if(ae.getSource() == PREVIOUS)
        {
            this.setVisible(false);
            this.dispose();
            NextPage t = new NextPage("Siddhant");
        }
    }
}