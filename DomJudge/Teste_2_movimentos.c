#include <stdio.h>
#include <math.h>
//Protótipos:
double velMRU(double, double);
double distMRU(double, double);
double tempoMRU(double, double);
double distMV(double, double, double);
double velInMV(double, double, double);
double velFimMV(double, double, double);
double TempMV(double, double, double);

int main(void) {
  int N,O,i;
  double vel, dist, temp, acel;
  scanf("%d", &N);
  for(i = 0; i < N; i ++){
    scanf("%d", &O);
    switch(O){
      case 1:{
        scanf("%lf", &vel);
        scanf("%lf", &temp);
        printf("%.2lf\n", distMRU(vel, temp));
      }break;
      case 2:{
        scanf("%lf", &dist);
        scanf("%lf", &temp);
        printf("%.2lf\n", velMRU(dist, temp));
      }break;
      case 3:{
        scanf("%lf", &dist);
        scanf("%lf", &vel);
        printf("%.2lf\n", tempoMRU(dist, vel));
      }break;
      case 4:{
        scanf("%lf", &vel);
        scanf("%lf", &acel);
        scanf("%lf", &temp);
        printf("%.2lf\n", distMV(vel, acel, temp));
      }break;
      case 5:{
         scanf("%lf", &vel);
        scanf("%lf", &acel);
        scanf("%lf", &temp);
        printf("%.2lf\n", velFimMV(vel, acel, temp));
      }break;
      case 6:{
        scanf("%lf", &dist);
        scanf("%lf", &acel);
        scanf("%lf", &temp);
        printf("%.2lf\n", velInMV(dist, acel, temp));
      }break;
      case 7:{
        scanf("%lf", &dist);
        scanf("%lf", &vel);
        scanf("%lf", &acel);
        printf("%.2lf\n", TempMV(dist, vel, acel));
      }break;
    }
  }
  return 0;
}

double distMRU(double vel, double temp){
  double dist;
  dist = vel * temp;
  return(dist);
}

double velMRU(double dist, double temp){
  double vel;
  vel = dist / temp;
  return(vel);
}

double tempoMRU(double dist, double vel){
  double temp;
  temp = dist / vel;
  return(temp);
}

double distMV(double vel, double acel, double temp){
  double dist;
  dist = (vel * temp) + ((acel * temp*temp))/2;
  return(dist);
}

double velFimMV(double vel, double acel, double temp){
  double velFim;
  velFim = vel + acel * temp;
  return(velFim);
}

double velInMV(double dist, double acel, double temp){
  double velIn;
  velIn = (dist - ((acel * temp*temp))/2) / temp;
  return(velIn);
}

double TempMV(double dist, double vel, double acel){
  double tempo, velFim;
  velFim = sqrt((vel*vel) + (2 * acel * dist));
  tempo = ((velFim - vel)/acel);
  return(tempo);
}
