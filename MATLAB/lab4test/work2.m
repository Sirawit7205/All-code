%Lab 4 test work 2 --> Sirawit Lappisatepun M.4/6 No.29
x=[1:10];
y1=[1 -4 -6 -10 -7 1 10 15 18 22];
y2=[0 2 4 12 16 6 10 2 -1 4];
y3=[5 -3 -6 1 6 4 10 7 2 -1];
plot(x,y1,'-Or','markeredgecolor','g','markerfacecolor','r')
hold on
plot(x,y2,'--db','markeredgecolor','g','markerfacecolor','b')
hold on
plot(x,y3,'-.sk','markeredgecolor','g','markerfacecolor','k')
title('X/Y Data')
xlabel('x')
ylabel('y')
legend('y1','y2','y3')
grid on
%Code Ended