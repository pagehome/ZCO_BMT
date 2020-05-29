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
import java.io.ByteArrayInputStream;

public class FileDecIns {
	public static void main(String args[]){

		byte[] errbyte = new byte[6];
		CubeOneAPI coc = new CubeOneAPI();
		coc.coinit (1, "API", "SA","","","","","","","",100);

		ResultSet rs = null;
		Connection con=null;
		PreparedStatement pstmt = null;
		InputStream in = null;

		byte[] decblob;

		String jdb="jdbc:oracle:thin:@192.168.1.70:1521:ORA11";
		String dbid="test";
		String dbpw="test";

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con = DriverManager.getConnection(jdb,dbid,dbpw);
			con.setAutoCommit(false);
			pstmt = con.prepareStatement("INSERT INTO BMT28 (COL_BLOB) VALUES( ?)");

			/* File load */
			java.io.File fl = new java.io.File("./"+args[0]);
			java.io.FileInputStream src = new java.io.FileInputStream(fl);
			int fileSize = (int)fl.length();	
			byte[] buffer = new byte[fileSize];
			int len = 0;
			System.out.println("FileSize=["+fileSize+"]");

			while ((len=src.read(buffer)) >= 0) {
				/* Decrypt File data */
				decblob = CubeOneAPI.codecbyte(new String(buffer), "SSN", 11, "", "", errbyte); 
				System.out.println("dec FileSize=["+decblob.length+"]");

				in=new ByteArrayInputStream( decblob );
				pstmt.setBinaryStream(1, in, decblob.length);
				pstmt.executeUpdate();
			}
			in.close();
			con.commit();
			System.out.println("SQL END");

		}catch(SQLException ee){
			ee.printStackTrace();
		}catch(Exception e){
			e.printStackTrace();

		}finally{
			try{rs.close();}catch(Exception e){}
			try{pstmt.close();}catch(Exception e){}
			try{con.close();}catch(Exception e){}
		}
	}
}

