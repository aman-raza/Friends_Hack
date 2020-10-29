import 'package:flutter/material.dart';
import 'package:liquid_swipe/liquid_swipe.dart';
void main() {
  runApp(new Directionality(textDirection: TextDirection.ltr, child: MyApp()));
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return LiquidSwipe(
      pages: [
        Container(color: Colors.white,),
        Container(color: Colors.teal,),
        Container(color: Colors.orange,),
        Container(color: Colors.red,),
        Container(color: Colors.blueGrey[900],),

      ],
      enableSlideIcon: true,
      positionSlideIcon: -0.6,
      slideIconWidget: Icon(Icons.arrow_back),
      waveType: WaveType.circularReveal,
    );
  }
}
