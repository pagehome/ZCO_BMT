import java.util.Date; import java.text.SimpleDateFormat;

import com.cubeone.*;

public class ThreadMain {

    public static void main(String[] args) {
        long startMills = 0L;
        long endmills = 0L;
        //CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100L);

        //System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
        //System.out.println("<<< CubeLog :: TheardMain.main() : Thread Performance Testing !!! <<<<<<<<");
        //System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

	//System.out.println("start time  :"+(startMills = System.currentTimeMillis()) +" "+(new SimpleDateFormat("HH:mm:ss")).format(new Date())+":start");

        SimpleDateFormat sdf1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        long startTime;
        startTime = System.currentTimeMillis();

        for(int i=0;i<700;i++) {
	   if ( (i%2)== 0) {
            Thread encThread = new EncThread();
            encThread.start();
                } else {

           // Thread encThread2 = new EncThread2();
           // encThread2.start();
                }
        }

         long endTime = System.currentTimeMillis();
         //System.out.println((new StringBuilder(String.valueOf(Thread.currentThread().getName()))).append(" End at ").append(sdf1.format(new Date())).append(" --> ").append(endTime - startTime).toString());


	//System.out.println(" finish time :"+(endmills = System.currentTimeMillis())+"  "+ (new SimpleDateFormat("HH:mm:ss")).format(new Date())+":end");
    }

}


