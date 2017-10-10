import csv
import matplotlib.pyplot as plt

def read_circle(file_path):
    with open(file_path) as file:
        reader = csv.reader(file)
        for data in reader:
            circle_x=float(data[0])
            circle_y=float(data[1])
            circle_radius=float(data[2])
        return circle_x,circle_y,circle_radius

def read_points(file_path):
    points_x=[]
    points_y=[]
    with open(file_path) as file:
        reader = csv.reader(file)
        for point in reader:
            points_x.append(float(point[0]))
            points_y.append(float(point[1]))
        return points_x,points_y

groundtruth_x,groundtruth_y=read_points("../build/ground_truth_points.data")
test_points_x,test_points_y=read_points("../build/test_points.data")
groundtruth_circle_x,groundtruth_circle_y,groundtruth_circle_radius=\
                            read_circle("../build/ground_truth_circle.data")
test_circle_x,test_circle_y,test_circle_radius=\
                            read_circle("../build/test_result.data")

plt.plot(groundtruth_x,groundtruth_y,'*', color='black')

circle_gt=plt.Circle((groundtruth_circle_x, groundtruth_circle_y), 
            groundtruth_circle_radius, color='grey',alpha=0.2)
plt.gcf().gca().add_artist(circle_gt)

x_max=groundtruth_circle_x+groundtruth_circle_radius
x_min=groundtruth_circle_x-groundtruth_circle_radius
y_max=groundtruth_circle_y+groundtruth_circle_radius
y_min=groundtruth_circle_y-groundtruth_circle_radius

x_max=max(x_max,test_circle_x+test_circle_radius)
x_min=min(x_min,test_circle_x-test_circle_radius)
y_max=max(y_max,test_circle_y+test_circle_radius)
y_min=min(y_min,test_circle_y-test_circle_radius)


plt.plot(test_points_x,test_points_y,'*', color='red')

circle_tr=plt.Circle((test_circle_x, test_circle_y), 
                      test_circle_radius, color='red',alpha=0.2)
plt.gcf().gca().add_artist(circle_tr)


plt.gcf().gca().set_xlim(x_min-10,x_max +10)
plt.gcf().gca().set_ylim(y_min-10,y_max +10)

plt.show()