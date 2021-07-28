/*
this code is base on the optimization of NP-problems
ths example of problem is url below
https://www.codeground.org/practice/practiceProblemViewNew
*/



double t_decrease = 0.99998; // temperature decrease every 
double t_crit = 0.00001;
double t = N*0.01;// temperature N is the num of input size
double k;//Boltzmann constant
E1 = 0;
E2 = 0;
li1.clear();
li1.resize(N, 0);
for(int i = 0 ; i < N ; i++){//init the state
  li1[i] = i;
}
li2.clear();
li2.resize(N, 0);
while (t > t_crit) {//t : temperature t_crit : critical temperature
  li2 = suffle(li1);
  E2 = optimize(li2);// optimize function calculate fitness
  k = E1*0.05;
  double p = exp((E1 - E2) / (t * k));
  if (p > (double)(rand() % 1000) / 1000) { // change rand(0~1)
    /*
    in the first temperature
    if N == 50
    E2 is greater than E1 by 10%
    then p is 0.0183156
    */
    E1 = E2;
    li1.assign(li2.begin(),li2.end());
  }
  t *= t_decrease;
}
//E1 is optimized answer and li1 is optimized list
