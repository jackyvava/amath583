import matplotlib.pyplot as plt

# 读取数据文件 sin_data.txt
x = []
y = []

# 打开并读取数据文件
with open("sin_data.txt", "r") as file:
    for line in file:
        # 分割每行数据并添加到 x 和 y 列表
        xi, yi = map(float, line.split())
        x.append(xi)
        y.append(yi)

# 绘制图形
plt.plot(x, y, label="sin(x)")
plt.title("Plot of sin(x)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()

# 显示图形
plt.show()

# 可选：将图形保存为图片文件
plt.savefig("sinx.png")
