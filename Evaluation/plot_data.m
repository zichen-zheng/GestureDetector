%PLOT_DATA is a MATLAB script to plot evaluation data of GestureDetector.

%   Written by    Zichen Zheng
%   Created on    Dec 6, 2013
%
%   Copyright (c) 2013 Zichen Zheng. All rights reserved.

clear all;
close all;

set(0,'DefaultAxesFontSize',15);

xlsfile = 'evaluation.xls';
sheet = 1;
data = xlsread(xlsfile, sheet);

numUniSamples = 244;
numCompSamples = 194;

text_xoffset = -0.29;
text_yoffset = 2.3;

%% win size
figure;
result = data(38:45,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]});
text(x_loc{1}+text_xoffset, acc+text_yoffset, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Accuracy (%)', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
axis([0 9 0 100]);
title('HOG Window Size');
export_fig('Figures/winsize', '-eps', '-transparent');

%% Linear SVM
figure;
result = data(1:6,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}+text_xoffset, acc+text_yoffset, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Regularization Term {\itC}', 'fontsize', 18);
ylabel('Accuracy (%)', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('Linear SVM');
axis([0 7 0 100]);
export_fig('Figures/linear-c', '-eps', '-transparent');

%% RBF: C
figure;
result = data(8:15,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1';'1e2';'1e3'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}+text_xoffset, acc+text_yoffset, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Regularization Term {\itC}', 'fontsize', 18);
ylabel('Accuracy (%)', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('RBF Kernel SVM (\gamma = 1 / num\_features)');
axis([0 9 0 100]);
export_fig('Figures/rbf-c', '-eps', '-transparent');

%% RBF: gamma
figure;
result = data(17:24,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'5e-4';'7.5e-4';'1e-3';'2.5e-3';'5e-3';'1e-2';'5e-2'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}+text_xoffset, acc+text_yoffset, num2str(acc,'%.2f'),'FontSize',12)
xlabel('RBF Parameter \gamma', 'fontsize', 18);
ylabel('Accuracy (%)', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('RBF Kernel SVM ({\itC} = 1)');
axis([0 9 0 100]);
export_fig('Figures/rbf-gamma', '-eps', '-transparent');

%% Trianing Time: HOG
figure;
result = data(38:45,1);
plot(result, 'o', 'MarkerSize', 10, 'LineWidth', 2);
title('Training Time Elapsed for Different HOG Window Size');
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
set(gca, 'xticklabel', xname)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Time (s)', 'fontsize', 18);
hold on;
plot(result, 'LineWidth', 2);
export_fig('Figures/train-time-hog', '-eps', '-transparent');

%% Testing Time: HOG
figure;
result = data(38:45,2:3);
result(:,1) = result(:,1) / numUniSamples * 1000;
result(:,2) = result(:,2) / numCompSamples * 1000;
plot(result, 'o', 'MarkerSize', 10, 'LineWidth', 2);
title('Testing Time Elapsed for Different HOG Window Size');
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
set(gca, 'xticklabel', xname)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Time (ms)', 'fontsize', 18);
hold on;
plot(result, 'LineWidth', 2);
legend('Uniform', 'Complex', 'Location','NorthWest');
export_fig('Figures/test-time-hog', '-eps', '-transparent');

%% Trianing Time: SVM
figure;
result = [data(1:6,1) data(8:13,1)];
plot(result, 'o', 'MarkerSize', 10, 'LineWidth', 2);
title('Training Time Elapsed for Different SVM Types');
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1'};
set(gca, 'xticklabel', xname)
xlabel('Regularization Term {\itC}', 'fontsize', 18);
ylabel('Time (s)', 'fontsize', 18);
hold on;
plot(result, 'LineWidth', 2);
legend('Linear', 'RBF', 'Location','NorthWest');
export_fig('Figures/train-time-svm', '-eps', '-transparent');

%% Testing Time: SVM
figure;
result = [(data(1:6,2)/numUniSamples+data(1:6,3)/numCompSamples)/2 ...
    (data(8:13,2)/numUniSamples+data(8:13,3)/numCompSamples)/2];
result = result * 1000;
plot(result, 'o', 'MarkerSize', 10, 'LineWidth', 2);
title('Testing Time Elapsed for Different SVM Types');
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1'};
set(gca, 'xticklabel', xname)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Time (ms)', 'fontsize', 18);
hold on;
plot(result, 'LineWidth', 2);
legend('Linear', 'RBF', 'Location','NorthWest');
export_fig('Figures/test-time-svm', '-eps', '-transparent');
