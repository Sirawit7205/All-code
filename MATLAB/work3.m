%Function value calculator (3)
%Sirawit Lappisatepun M.4/6 No.29
x=[-3:0.01:1];
y=((2.*x)./((2.*x)-5))+(sin(4.*pi.*x)./exp(x));
plot(x,y)
xlabel('x')
ylabel('y')
title('Function value calculation from -3 to 1')
legend('((2.*x)./((2.*x)-5))+(sin(4.*pi.*x)./exp(x))')