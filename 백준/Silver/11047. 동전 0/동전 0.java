import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		int N=s.nextInt();
		int K=s.nextInt();
		
		int[] A=new int[N];
		for(int i=0; i<N; i++) {
			A[i]=s.nextInt();
		}
		
		int cnt=0;
		for(int i=N-1; i>=0; i--) {
			if(K/A[i]!=0) {
				cnt+=K/A[i];
				K=K%A[i];
			}
		}

		System.out.println(cnt);
	}

}
