import java.io.IOException;
import java.util.Scanner;


public class Main {

    public static double calcDist(int x, int y, int exX, int exY, int range) {
        Double result = Math.sqrt(Math.pow(x-exX, 2) + Math.pow(y-exY, 2));
        return result;

    }

    public static void main(String[] args) throws IOException {

        Scanner scan = new Scanner(System.in);
        int line1[] = new int[4];
        String line2[] = new String[4];
        int coordinatesMagic[] = new int[2];
        int cornersUnit[] = new int[4];
        boolean finished;

        int range = 0;
        int damage = 0;

        int tries = scan.nextInt();
        for (int i = 0; i < tries; i++) {

            finished = false;

            line1[0] = scan.nextInt();
            line1[1] = scan.nextInt();
            line1[2] = scan.nextInt();
            line1[3] = scan.nextInt();
            scan.nextLine();
            line2 = scan.nextLine().split(" ");

            switch (line2[0]) {
                case "fire" :
                    damage = 200;
                    switch (line2[1]) {
                        case "1" :
                            range = 20;
                            break;
                        case "2" :
                            range = 30;
                            break;
                        case "3" :
                            range = 50;
                            break;
                    }
                    break;
                case "water" :
                    damage = 300;
                    switch (line2[1]) {
                        case "1" :
                            range = 10;
                            break;
                        case "2" :
                            range = 25;
                            break;
                        case "3" :
                            range = 40;
                            break;
                    }
                    break;
                case "earth" :
                    damage = 400;
                    switch (line2[1]) {
                        case "1" :
                            range = 25;
                            break;
                        case "2" :
                            range = 55;
                            break;
                        case "3" :
                            range = 70;
                            break;
                    }
                    break;
                case "air" :
                    damage = 100;
                    switch (line2[1]) {
                        case "1" :
                            range = 18;
                            break;
                        case "2" :
                            range = 38;
                            break;
                        case "3" :
                            range = 60;
                            break;
                    }
                    break;
            }

            coordinatesMagic[0] = Integer.parseInt(line2[2]);
            coordinatesMagic[1] = Integer.parseInt(line2[3]);
            
            cornersUnit[0] = line1[2];
            cornersUnit[1] = line1[2] + line1[0];
            cornersUnit[2] = line1[3];
            cornersUnit[3] = line1[3] + line1[1];

            if (coordinatesMagic[0] >= cornersUnit[0] && coordinatesMagic[0] <= cornersUnit[1] && coordinatesMagic[1] >= cornersUnit[2] && coordinatesMagic[1] <= cornersUnit[3]) {
                finished = true;
            }

            if (!finished) {
                for (int j = cornersUnit[2]; j < cornersUnit[3] + 1; j++) {
                    if ((calcDist(cornersUnit[0], j, coordinatesMagic[0], coordinatesMagic[1], range)) <= range || (calcDist(cornersUnit[1], j, coordinatesMagic[0], coordinatesMagic[1], range)) <= range) {
                        finished = true;
                        break;
                    }
                }
                if (!finished) {
                    for (int k = cornersUnit[0]; k < cornersUnit[1] + 1; k++) {
                        if ((calcDist(k, cornersUnit[2], coordinatesMagic[0], coordinatesMagic[1], range)) <= range || (calcDist(k, cornersUnit[3], coordinatesMagic[0], coordinatesMagic[1], range)) <= range) {
                            finished = true;
                            break;
                        }
                    }
                }
            }

            if (finished) {
                System.out.println(damage);
            } else {
                System.out.println(0);
            }           

        }
    }
}