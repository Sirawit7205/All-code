X=1:10;
Y1=[1 -4 -6 -10 -7 1 10 15 18 22];
Y2=[0 2 4 12 16 6 10 2 -1 4];
plot(X,Y1,'r')
hold on
plot(X,Y2,'b--')
xlabel('x');
ylabel('y');
legend('Y1','Y2')
grid on