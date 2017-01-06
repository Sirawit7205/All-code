%Function value calculator (2)
%Sirawit Lappisatepun M.4/6 No.29
x=[-3:0.1:5];
y=(0.3.*x)+(2.3./(2+exp(1-(2.3.*x))));
plot(x,y,'m')
xlabel('x')
ylabel('y')
title('Function value calculation from -3 to 5')
legend('(0.3.*x)+(2.3./(2+exp(1-(2.3.*x))))')