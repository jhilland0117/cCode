%This is the matlab file that plots a file
A = dlmread('hist.txt');
B = dlmread('hist.txt');
stem(A);
grid on;
pause;
plot(B);
grid on;
