X=1:0.1:10;
Y=1:0.1:10;
[x,y]=meshgrid(X,Y);
z=(((x+y)./x).^2)+((x+(3.*y)).^(0.5.*((2.*x)+y)));
subplot(1,2,1)
mesh(x,y,z)
subplot(1,2,2)
surf(x,y,z)