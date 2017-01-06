x=[0:0.1:52];
y=0.4*sqrt(1.8*x);
plot(x,y)
xlabel('Distance (km)');
ylabel('Height (km)');
title('Missile Height as a Function of Downrange Distance');
axis ([0 52 0 5]);