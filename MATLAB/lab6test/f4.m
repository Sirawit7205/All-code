clear;
clc;
a=1;
for t=-5:0.1:50
if t>=0&&t<=10
    v(a)=(12*(t^2))-(6*t);
elseif t>10&&t<=20
    v(a)=1200-(6*t);
elseif t>20&&t<=30
    v(a)=(54*t)+(3*((t-20)^2));
elseif t>30
    v(a)=1920*exp(-0.2*(t-30));
else
    v(a)=0;
end
a=a+1;
end
t=-5:0.1:50;
plot(t,v)
title('Velocity and time')
xlabel('time(s)')
ylabel('velocity(m)')
