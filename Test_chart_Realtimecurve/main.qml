import QtQuick 2.12
import QtQuick.Controls 2.5
import QtCharts 2.13
import com.mycompany.qmlcomponents 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    GraphList {
        id: graphlist
    }

    ChartView {
        id:chartView
        title: qsTr("①侧温度趋势")
        titleFont.pixelSize: 15
        titleFont.bold: true
        titleColor: "black"
        width: parent.width
        height:parent.height
        antialiasing: true
        //X轴
        ValueAxis {
            id: valueAxisX
            min: 0
            max: 10
            tickCount: 10 //坐标轴上的的刻度个数。所以间隔 = 60 / 30 = 2
            labelFormat: "%.0f"//0 - 控制小数点后有几位小数
        }
        //Y轴
        ValueAxis {
            id: valueAxisY
            min: 0
            max: 10
            tickCount: 10  //坐标轴上的的刻度个数
            labelFormat: "%.1f"//1 - 控制小数点后有几位小数
        }
        //LineSeries是折线，SplineSeries是曲线。子项都是XYPoint
        SplineSeries {
            id:line1
            name: "1"  //线条的名称
            axisX: valueAxisX  //指定X轴
            axisY: valueAxisY  //指定Y轴
            color: Qt.darker("#BB4444",1.2) //线条颜色，默认每条线的颜色不同
            width: 2//线的宽度，但修改线宽后，需要重新设置color，否则修改过width的线条都是黑色
        }
    }
    Timer{
            id:timer
            interval: 1000;running:true;repeat: true;
            onTriggered: timeChanged();
        }
    function timeChanged() {
        graphlist.istimeOut(); //显示调用timeout，刷新C++类中的数据
        line1.clear();
        //clear后重新添加数据
        for(var i = 0;i < graphlist.lineSize;i++){
            line1.append(i,graphlist.getDataSource(i));
        }
        if(graphlist.lineSize >valueAxisX.max)
        {
            valueAxisX.max++;
            valueAxisX.min++;
        }
    }

}
