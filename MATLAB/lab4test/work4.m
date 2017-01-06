%Lab 4 test work 4 --> Sirawit Lappisatepun M.4/6 No.29
x=[0:0.01:1];
y=[0:0.01:1];
[X,Y]=meshgrid(x,y);
Z=X.*(1-X).*Y.*(1-Y).*atan(100.*(((X+Y)./sqrt(2))-0.8));
subplot(2,1,1)
contour(X,Y,Z)
title('Contour')
xlabel('X')
ylabel('Y')
subplot(2,1,2)
contourf(X,Y,Z)
title('Contour Fill')
xlabel('X')
ylabel('Y')
%Code Ended