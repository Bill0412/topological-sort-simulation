nRows = 8;
data(:, 5) = zeros(nRows, 1);
for i = 1:nRows
    data(i, 5) = mean(data(i, 2:4));
end
figure(1);
hold on;
title("Hash Reconstruction");
plot(data(:, 1), data(:, 5), '-*');
xlabel("Hash Table Size (3 times the numbers inserted)");
ylabel("Time Cost / s");
