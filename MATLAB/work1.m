%Function value calculator (1)
%Sirawit Lappisatepun M.4/6 No.29
x=[-4:0.1:4];
y=[-8:0.1:8];
a=(x.^5)-(5.*(x.^4))-(35.*(x.^3))+(125.*(x.^2))+(194.*x)-280;
b=(y.^5)-(5.*(y.^4))-(35.*(y.^3))+(125.*(y.^2))+(194.*y)-280;
subplot(2,1,1)
plot(x,a,'g')
xlabel('x')
ylabel('y')
title('Function value calculation from -4 to 4')
legend('(x.^5)-(5.*(x.^4))-(35.*(x.^3))+(125.*(x.^2))+(194.*x)-280')
subplot(2,1,2)
plot(y,b,'r')
xlabel('x')
ylabel('y')
title('Function value calculation from -8 to 8')
legend('(x.^5)-(5.*(x.^4))-(35.*(x.^3))+(125.*(x.^2))+(194.*x)-280')