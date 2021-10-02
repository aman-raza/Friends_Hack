import 'package:flutter/material.dart';
import 'dart:math';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen>
    with SingleTickerProviderStateMixin {
  int leftDice = 1;
  int rightDice = 1;
  AnimationController _controller;
  CurvedAnimation animation;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    animate();
  }

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    _controller.dispose();
  }

  animate() {
    _controller =
        AnimationController(duration: Duration(seconds: 2), vsync: this);
    animation = CurvedAnimation(parent: _controller, curve: Curves.bounceOut);

    //_controller.forward();
    animation.addListener(() {
      setState(() {});
      print(_controller.value);
    });

    animation.addStatusListener((status) {
      if (status == AnimationStatus.completed) {
        setState(() {
          leftDice = Random().nextInt(6) + 1;
          rightDice = Random().nextInt(6) + 1;
        });
        print('Completed');
        _controller.reverse();
      }
    });
  }

  void roll() {
    _controller.forward();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Dice Game'),
        backgroundColor: Colors.green[400],
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Row(
              children: [
                Expanded(
                  child: GestureDetector(
                    onDoubleTap: roll,
                    child: Padding(
                        padding: EdgeInsets.all(15.0),
                        child: Image(
                          height: 200 - (_controller.value * 200),
                          image: AssetImage(
                              'assets/images/dice-png-$leftDice.png'),
                        )),
                  ),
                ),
                Expanded(
                    child: GestureDetector(
                  onDoubleTap: roll,
                  child: Padding(
                      padding: EdgeInsets.all(15.0),
                      child: Image(
                        height: 200 - ((animation.value) * 200),
                        image:
                            AssetImage('assets/images/dice-png-$rightDice.png'),
                      )),
                )),
              ],
            ),
            RaisedButton(
              onPressed: roll,
              child: Text(
                'ROLL',
                style: TextStyle(color: Colors.black),
              ),
              color: Colors.lightGreen[300],
              splashColor: Colors.yellowAccent,
              
            ),
          ],
        ),
      ),
    );
  }
}
