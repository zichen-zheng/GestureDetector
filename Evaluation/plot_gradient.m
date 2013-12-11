function plot_gradient(img)

set(0,'DefaultAxesFontSize',18);

img_gray = rgb2gray(img);
[y_len x_len] = size(img_gray);
X = 1 : x_len;
Y = 1 : y_len;
Y = fliplr(Y);
[DX DY] = gradient(double(img_gray),-1,1);

figure(1);
quiver(X,Y,DX,DY);
title('Gradient Field');
axis([1 x_len 1 y_len]);
%axis([24 44 102 122]);
export_fig gradient.eps -transparent;