import java.util.*;

public class Hamming {
    //hamming code
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        System.out.println("enter message string: ");
        String m=sc.next();
        int r=countR(m.length());
        int total=m.length()+r;
        int[] bits=new int[total];
        int twosp=0;
        while (Math.pow(2,twosp)<=total){
            bits[(int)Math.pow(2,twosp)-1]=-1;
            twosp+=1;
        }
        int k=0;
        for(int i=total-1;i>=0;i--){
            if(bits[i]!=-1) {
                bits[i] = m.charAt(k)-'0';
                k += 1;
            }
        }
        TreeMap<Integer,Integer> map=new TreeMap<>();
        makeFinalMap(map,total,bits,r);
        for(int key: map.keySet()){
            bits[key-1]=map.get(key)%2==1 ? 1 : 0;
        }
        System.out.println(map);
        for(int i=0;i<total;i++){
            if(bits[i]==-1){
                bits[i]=0;
            }
        }
        System.out.println(Arrays.toString(bits));
        //adding error
        System.out.println("please enter bit to change");
        int cBit=sc.nextInt();
        while(cBit>total){
            System.out.println("please enter correct bit to change");
            cBit=sc.nextInt();
        }
        bits[cBit-1]=bits[cBit-1]==0?1:0;
        TreeMap<Integer,Integer> map2=new TreeMap<>();
        makeFinalMap(map2,total,bits,r);
        StringBuilder sb=new StringBuilder();
        for(int key:map2.keySet()) {
            sb.insert(0,map2.get(key) % 2 == 1 ? 1 : 0);
        }
        int ans=binaryToDecimal(sb);
        System.out.println("the changed bit is");
        System.out.println(ans);
    }
    public static void makeFinalMap(TreeMap<Integer,Integer> map,int total,int[] bits,int r){
        for(int i=0;i<total;i++){
            int t=1;
            for(int j=0;j<r;j++){
                if(((i+1)&t)==t && bits[i]==1){
                    map.put(t,map.getOrDefault(t,0)+1);
                }
                t*=2;
            }
        }
    }
    public static int countR(int m){
        int i=0;
        while (true) {
            if (Math.pow(2, i) >= m + i + 1) {
                return i;
            }
            i += 1;
        }
    }
    public static int binaryToDecimal(StringBuilder sb){
        int ans=0;
        int t=0;
        for(int i=sb.length()-1;i>=0;i--){
            ans+=(sb.charAt(i)-'0')*Math.pow(2,t);
            t+=1;
        }
        return ans;
    }
}

