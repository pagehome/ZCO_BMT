import java.util.Date;
import java.text.SimpleDateFormat;

import com.cubeone.*;

public class ThreadMain {

    public static void main(String[] args) {
        //CubeOneAPI.coinit (1, "OBCS", "cubeapi", "","","","","","","",100L);

        System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
        System.out.println("<<< CubeLog :: TheardMain.main() : Thread Performance Testing !!! <<<<<<<<");
        System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

        SimpleDateFormat sdf1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        long startTime;
        startTime = System.currentTimeMillis();

        for(int i=0;i<700;i++) {
            Thread encThread = new EncThread();
            System.out.println("<<< CubeLog :: TheardMain.main() : thread-cnt=" + i);
            encThread.start();
        }

        // long endTime = System.currentTimeMillis();
        // System.out.println((new StringBuilder(String.valueOf(Thread.currentThread().getName()))).append(" End at ").append(sdf1.format(new Date())).append(" --> ").append(endTime - startTime).toString());

    }

}


