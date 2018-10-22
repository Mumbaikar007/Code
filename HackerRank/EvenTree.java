import java.util.*;
 
public class EvenTree{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        Integer[][] edges = new Integer[M][2];
        for(int i=0;i<M;i++){
            edges[i][0] = in.nextInt();
            edges[i][1] = in.nextInt();
            if(edges[i][0]>edges[i][1]){
                int tmp = edges[i][0];
                edges[i][0] = edges[i][1];
                edges[i][1] = tmp;
            }
        }
        Arrays.sort(edges,new Comparator<Integer[]>(){
            @Override
            public int compare(Integer[] int1, Integer[] int2){
                Integer v1 = int1[0];
                Integer v2 = int2[0];
                return v1.compareTo(v2);
            }
        });
        int[] count = new int[N];
        count[0] = N;
        for(int i=1;i<N;i++){
            ArrayList<Integer> a = new ArrayList<Integer>();
            a.add(i+1);
            int j = 0;
            while(j<a.size()){
                for(int m=j;m<M;m++){
                    if(edges[m][0]==a.get(j)){
                        if(!a.contains(edges[m][1])){
                            a.add(edges[m][1]);
                        }
                    }
                }
                j++;
            }
            count[i] = a.size();
        }
        int remove = 0;
        for(int c:count){
            if(c%2==0)
                remove++;
        }
        System.out.println(remove-1);                   
    }
}