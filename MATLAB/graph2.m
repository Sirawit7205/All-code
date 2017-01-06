x=[0:0.01:2];
y=sinh(x);
z=tanh(x);
%plot(x,y,'-.r',x,z,'--c')
%xlabel('x')
%ylabel('Hyperbolic Sine and Hyperbolic Tangent')
%legend('sinh(x)','tanh(x)')
subplot(1,2,1)
plot(x,y,'--r')
xlabel('x')
ylabel('sin(x)')
legend('sinh(x)')
subplot(1,2,2)
plot(x,z,'dc')
xlabel('x')
ylabel('tan(x)')
legend('tanh(x)')