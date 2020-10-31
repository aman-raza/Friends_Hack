var app=angular.module('calculator', [])
    app.controller('count', function($scope) {
        $scope.result = function() {
            if ($scope.operation == '+') {
                return $scope.a + $scope.b;
            }
            if ($scope.operation == '-') {
                return $scope.a - $scope.b;
            }
            if ($scope.operation == '*') {
                return $scope.a * $scope.b;
            }
            if ($scope.operation == '/') {
                return $scope.a / $scope.b;
            }
        };
    });