import java.sql.Connection;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.cubeone.CubeOneAPI;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;

public class FileToIns {
	public static void main(String args[]){
		Connection con=null;
		PreparedStatement pstmt = null;

		String jdb="jdbc:oracle:thin:@192.168.1.70:1521:ORA11";
		String dbid="test";
		String dbpw="test";

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con = DriverManager.getConnection(jdb,dbid,dbpw);
			pstmt = con.prepareStatement("INSERT INTO BMT28 (COL_BLOB,COL_NUMBER) VALUES(?,?)");

			/* File load */
			java.io.File fl = new java.io.File("./" + args[0]);
			java.io.FileInputStream src = new java.io.FileInputStream(fl);
			int fileSize = (int)fl.length();	

			System.out.println("FileSize=["+fileSize+"]");

			pstmt.setBinaryStream(1, src, fileSize);
			pstmt.setInt(2, 1);
			pstmt.executeUpdate();
			con.commit();
			src.close();
			pstmt.close();	
			con.close();	

			System.out.println("SQL END");

		}catch(SQLException ee){
			ee.printStackTrace();                                             
		}catch(Exception e){
			e.printStackTrace();         

		}finally{                                                                
			try{pstmt.close();}catch(Exception e){}                          
			try{con.close();}catch(Exception e){}                           
		}
	}                       
}

