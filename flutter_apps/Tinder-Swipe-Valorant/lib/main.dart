
import 'package:flutter/material.dart';
import 'package:flutter_tindercard/flutter_tindercard.dart';
void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title:"Valorant Agents",
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: Colors.blueGrey[900],
        scaffoldBackgroundColor: Colors.blueGrey[900],
      ),
      home:Tinderswiper(),

    );
  }
}

class Tinderswiper extends StatefulWidget {
  @override
  _TinderswiperState createState() => _TinderswiperState();
}

class _TinderswiperState extends State<Tinderswiper> with TickerProviderStateMixin{

  List<String> tinderimages=[
    "https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcSZQ1rH-tm77qiKdgt2ENPnTI_GsXRyA6AfAg&usqp=CAU",
    "https://i.pinimg.com/originals/15/f2/79/15f279fdfaafec59ee5f4bb78f208d1c.jpg",
    "https://i.pinimg.com/originals/33/94/ba/3394ba96497429811a5caf00f71981f6.jpg",
    "https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/bbb685b6-9c0f-449e-9ab7-55748fadbe25/de05w1j-37df1d45-f65c-4809-878d-858f53d9d905.png/v1/fill/w_833,h_551,q_80,strp/viper_wallpaper_by_lumija_art_de05w1j-fullview.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOiIsImlzcyI6InVybjphcHA6Iiwib2JqIjpbW3siaGVpZ2h0IjoiPD01NTEiLCJwYXRoIjoiXC9mXC9iYmI2ODViNi05YzBmLTQ0OWUtOWFiNy01NTc0OGZhZGJlMjVcL2RlMDV3MWotMzdkZjFkNDUtZjY1Yy00ODA5LTg3OGQtODU4ZjUzZDlkOTA1LnBuZyIsIndpZHRoIjoiPD04MzMifV1dLCJhdWQiOlsidXJuOnNlcnZpY2U6aW1hZ2Uub3BlcmF0aW9ucyJdfQ.bkJ73Y77i1MGMZyx3s4NA1bjNiSZ2QW9QoDlEr7aqPM",
    "https://i.pinimg.com/originals/f8/2f/4c/f82f4c72c2f771517a3ff68a90ffb4c5.jpg",
    "https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/bbb685b6-9c0f-449e-9ab7-55748fadbe25/de05w1j-37df1d45-f65c-4809-878d-858f53d9d905.png/v1/fill/w_833,h_551,q_80,strp/viper_wallpaper_by_lumija_art_de05w1j-fullview.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOiIsImlzcyI6InVybjphcHA6Iiwib2JqIjpbW3siaGVpZ2h0IjoiPD01NTEiLCJwYXRoIjoiXC9mXC9iYmI2ODViNi05YzBmLTQ0OWUtOWFiNy01NTc0OGZhZGJlMjVcL2RlMDV3MWotMzdkZjFkNDUtZjY1Yy00ODA5LTg3OGQtODU4ZjUzZDlkOTA1LnBuZyIsIndpZHRoIjoiPD04MzMifV1dLCJhdWQiOlsidXJuOnNlcnZpY2U6aW1hZ2Uub3BlcmF0aW9ucyJdfQ.bkJ73Y77i1MGMZyx3s4NA1bjNiSZ2QW9QoDlEr7aqPM",
  ];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Center(child: Text("Valorant Agents")),
      ),
      body:Center(
        child: Container(
          height: MediaQuery.of(context).size.height*0.7,
          child: TinderSwapCard(
            orientation: AmassOrientation.TOP,
            totalNum: 5,
            stackNum: 3,
            maxWidth: MediaQuery.of(context).size.width*0.9,
            maxHeight: MediaQuery.of(context).size.width*1.1,
            minWidth: MediaQuery.of(context).size.width*0.8,
            minHeight: MediaQuery.of(context).size.width*0.9,

            cardBuilder: (context,index)=>Card(
              child:Padding(
                padding: EdgeInsets.all(.0),
                child: Image.network('${tinderimages[index]}',fit: BoxFit.fill,),
              ),
              elevation: 10.0,
            ),
          ),
        ),
      ),
    );
  }
}
