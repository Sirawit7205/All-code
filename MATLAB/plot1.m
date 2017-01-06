x=-pi:pi/100:pi;
y=cos(4*x).*sin(10*x).*exp(-abs(x));
z=sin(3*x)+exp(x);
plot3(x,y,z,'b-');
grid on
title('Stress-Strain');
xlabel('Force (N)');
ylabel('Distance (m)');