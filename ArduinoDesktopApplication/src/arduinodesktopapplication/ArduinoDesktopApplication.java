/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arduinodesktopapplication;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

/**
 *
 * @author Neo
 */
public class ArduinoDesktopApplication {
    
    String serverHostname1;
    DatagramSocket d1;
    InetAddress ip,retiip;
    DatagramPacket send,rec;
    String modifiedSentence;
    
    public void led(String s){
        try{
            byte[] b=(s.getBytes());
           byte[] receiveData = new byte[1024]; 
    serverHostname1 = new String ("192.168.1.105");
    
   ip = InetAddress.getByName(serverHostname1); 
   
   
    d1 = new DatagramSocket();
    
    send =  new DatagramPacket(b,b.length, ip, 8032);
    
       
    d1.send(send); 
    
   rec =  new DatagramPacket(receiveData, receiveData.length); 
   
   d1.setSoTimeout(10000);
   
              d1.receive(rec); 
           modifiedSentence =   new String(rec.getData()); 
  
           InetAddress returnIPAddress = rec.getAddress();
     
           int port = rec.getPort();
           
            System.out.println ("From server at: " + returnIPAddress + 
                               ":" + port);
           System.out.println("Message: " + modifiedSentence); 
   
    d1.close(); 
        }catch(Exception e){
            System.out.println("Error:"+e);
        }
    }
    
    }
