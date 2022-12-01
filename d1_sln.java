import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;



class d1_sln {
    public static void main(String[] args) throws FileNotFoundException {
        File in = new File("d1_input.txt");
        Scanner f = new Scanner(in);
        String line;
        int sum = 0;
        ArrayList<Integer> o = new ArrayList<Integer>();
        while(f.hasNextLine()){
            line = f.nextLine();
            if(line.length() == 0) {
                o.add(sum);
                sum = 0;
                continue;
            }
            sum += Integer.valueOf(line);
        }
        Collections.sort(o,Collections.reverseOrder());
        System.out.println(o.get(0) + o.get(1) + o.get(2));
        f.close();
    }
}