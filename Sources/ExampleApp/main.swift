// The Swift Programming Language
// https://docs.swift.org/swift-book
import Foundation
import DetoursExample
import WinSDK

print("Hello, world!")
var callback: RaiseFailFastExceptionCallback = { record, context, flags in
    print("RaiseFailFastException Detoured!")
}

DetourRaiseFailFastException(callback)
RaiseFailFastException (nil, nil, 0)
