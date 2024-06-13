import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		int N=s.nextInt();
		
		int[] P=new int[N];
		
		for(int i=0; i<N; i++) {
			P[i]=s.nextInt();
		}
		
		int least, temp;
		for(int i=0; i<N-1; i++) {
			least=i;
			for(int j=i+1; j<N; j++) {
				if(P[least]>P[j]) {
					least=j;
				}
			}
			temp=P[i];
			P[i]=P[least];
			P[least]=temp;
		}
		
		int[] sum=new int[N];
		sum[0]=P[0];
		for(int i=1; i<N; i++) {
			sum[i]=sum[i-1]+P[i];
		}
		
		int total=0;
		
		for(int i=0; i<N; i++) {
			total+=sum[i];
		}
		
		System.out.println(total);

	}

}
