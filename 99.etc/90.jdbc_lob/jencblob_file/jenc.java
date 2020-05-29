import java.sql.Connection;
import java.sql.SQLException;
import com.cubeone.CubeOneAPI;

public class jenc {
	public static oracle.sql.BLOB jencblobinsb (Connection con, byte[] inval)  throws Exception {
		String encVal;
		oracle.sql.BLOB outBLOB = null;

		//byte[] inbuf = new byte[256];
		//byte[] inbuf = new byte[1024];
		byte[] err = new byte[5];
		//byte[] inbuf = inval.getBytes();
		long sizeBLOB = inval.length;

		java.io.InputStream rd = new java.io.ByteArrayInputStream (inval);
		if ((int) sizeBLOB == 0) {
			throw new SQLException ("No Data", "LOB", 0);
		}
		else {
			try {
				outBLOB = oracle.sql.BLOB.createTemporary(con, false, oracle.sql.BLOB.DURATION_SESSION);
			} catch (java.sql.SQLException ex ) {
				throw new SQLException ("No connection", "LOB", 0);
			}

			outBLOB.open(oracle.sql.BLOB.MODE_READWRITE);
			java.io.OutputStream out = outBLOB.getBinaryOutputStream();
			//java.io.OutputStream out = outBLOB.getBinaryOutputStream(0);
			int lenBuf = -1;
			while ((lenBuf=rd.read(inval)) >= 0) {
				encVal = CubeOneAPI.coencbytes(inval,lenBuf,"SSN", 11, "", "", err);
				if (err[0] == '2') {
					throw new SQLException ("failed enc to encVal", "LOB",0);
				}
				else {
					try {
						out.write(encVal.getBytes());
					}
					catch (java.io.IOException e) {
						out.close();
						outBLOB.close();
						throw new SQLException ("failed write to outBLOB", "LOB",0);
					}
				} //enc err check and write
			} //read blob data , end of WHILE
			out.flush();
			out.close();
			if (outBLOB.length() < 0) {
				outBLOB.close();
				//System.out.println("outBLOB = " + outBLOB.length());
				return null;
			}
		}
		System.out.println("inval len =" + inval.length + "  outBLOB len = " + outBLOB.length());
		outBLOB.close();
		return outBLOB;
	}

	public static oracle.sql.BLOB jencblobins (Connection con, oracle.sql.BLOB inval)  throws Exception {
		String encVal;
		oracle.sql.BLOB outBLOB = null;

		//byte[] inbuf = new byte[256];
		//byte[] inbuf = new byte[1024];
		byte[] err = new byte[5];
		byte[] inbuf = inval.getBytes();
		long sizeBLOB = inval.length();

		java.io.InputStream rd = inval.getBinaryStream();
		if ((int) sizeBLOB == 0) {
			throw new SQLException ("No Data", "LOB", 0);
		}
		else {
			try {
				outBLOB = oracle.sql.BLOB.createTemporary(con, false, oracle.sql.BLOB.DURATION_SESSION);
			} catch (java.sql.SQLException ex ) {
				throw new SQLException ("No connection", "LOB", 0);
			}

			outBLOB.open(oracle.sql.BLOB.MODE_READWRITE);
			java.io.OutputStream out = outBLOB.getBinaryOutputStream();
			//java.io.OutputStream out = outBLOB.getBinaryOutputStream(0);
			int lenBuf = -1;
			while ((lenBuf=rd.read(inbuf)) >= 0) {
				encVal = CubeOneAPI.coencbytes(inbuf,lenBuf,"SSN", 11, "", "", err);
				if (err[0] == '2') {
					throw new SQLException ("failed enc to encVal", "LOB",0);
				}
				else {
					try {
						out.write(encVal.getBytes());
					}
					catch (java.io.IOException e) {
						out.close();
						outBLOB.close();
						throw new SQLException ("failed write to outBLOB", "LOB",0);
					}
				} //enc err check and write
			} //read blob data , end of WHILE
			out.flush();
			out.close();
			if (outBLOB.length() < 0) {
				outBLOB.close();
				//System.out.println("outBLOB = " + outBLOB.length());
				return null;
			}
		}
		System.out.println("inval len =" + inval.length() + "  outBLOB len = " + outBLOB.length());
		outBLOB.close();
		return outBLOB;
	}
	public static oracle.sql.BLOB jdecblobinsb (Connection con, byte[] encVal)  throws Exception {
		byte[] decVal;

		oracle.sql.BLOB outBLOB = null;

		//byte[] inbuf = new byte[256];
		//byte[] inbuf = new byte[1024];
		byte[] err = new byte[5];
		//byte[] inbuf = encVal.getBytes();
		long sizeBLOB = encVal.length;

		java.io.InputStream rd = new java.io.ByteArrayInputStream (encVal);
		if ((int) sizeBLOB == 0) {
			throw new SQLException ("No Data", "LOB", 0);
		}
		else {
			try {
				outBLOB = oracle.sql.BLOB.createTemporary(con, false, oracle.sql.BLOB.DURATION_SESSION);
			} catch (java.sql.SQLException ex ) {
				throw new SQLException ("No connection", "LOB", 0);
			}

			outBLOB.open(oracle.sql.BLOB.MODE_READWRITE);
			java.io.OutputStream out = outBLOB.getBinaryOutputStream();
			//java.io.OutputStream out = outBLOB.getBinaryOutputStream(0);
			int lenBuf = -1;
			while ((lenBuf=rd.read(encVal)) >= 0) {
				decVal = CubeOneAPI.codecbyte(new String(encVal,0,lenBuf),"SSN", 11, "", "", err);
				if (err[0] == '2') {
					throw new SQLException ("failed dec to encVal", "LOB",0);
				}
				else {
					try {
						out.write(decVal);
					}
					catch (java.io.IOException e) {
						out.close();
						outBLOB.close();
						throw new SQLException ("failed write to outBLOB", "LOB",0);
					}
				} //enc err check and write
			} //read blob data , end of WHILE
			out.flush();
			out.close();
			if (outBLOB.length() < 0) {
				outBLOB.close();
				//System.out.println("outBLOB = " + outBLOB.length());
				return null;
			}
		}
		System.out.println("encVal len =" + encVal.length + "  outBLOB len = " + outBLOB.length());
		outBLOB.close();
		return outBLOB;
	}

	public static oracle.sql.BLOB jdecblobins (Connection con, oracle.sql.BLOB encVal)  throws Exception {
		byte[] decVal;
		oracle.sql.BLOB outBLOB = null;

		//byte[] inbuf = new byte[256];
		//byte[] inbuf = new byte[1024];
		byte[] err = new byte[5];
		byte[] inbuf = encVal.getBytes();
		long sizeBLOB = encVal.length();

		java.io.InputStream rd = encVal.getBinaryStream();
		if ((int) sizeBLOB == 0) {
			throw new SQLException ("No Data", "LOB", 0);
		}
		else {
			try {
				outBLOB = oracle.sql.BLOB.createTemporary(con, false, oracle.sql.BLOB.DURATION_SESSION);
			} catch (java.sql.SQLException ex ) {
				throw new SQLException ("No connection", "LOB", 0);
			}

			outBLOB.open(oracle.sql.BLOB.MODE_READWRITE);
			java.io.OutputStream out = outBLOB.getBinaryOutputStream();
			//java.io.OutputStream out = outBLOB.getBinaryOutputStream(0);
			int lenBuf = -1;
			while ((lenBuf=rd.read(inbuf)) >= 0) {
				decVal = CubeOneAPI.codecbyte(new String(inbuf,0,lenBuf),"SSN", 11, "", "", err);
				if (err[0] == '2') {
					throw new SQLException ("failed dec to encVal", "LOB",0);
				}
				else {
					try {
						out.write(decVal);
					}
					catch (java.io.IOException e) {
						out.close();
						outBLOB.close();
						throw new SQLException ("failed write to outBLOB", "LOB",0);
					}
				} //enc err check and write
			} //read blob data , end of WHILE
			out.flush();
			out.close();
			if (outBLOB.length() < 0) {
				outBLOB.close();
				//System.out.println("outBLOB = " + outBLOB.length());
				return null;
			}
		}
		System.out.println("encVal len =" + encVal.length() + "  outBLOB len = " + outBLOB.length());
		outBLOB.close();
		return outBLOB;
	}

}
