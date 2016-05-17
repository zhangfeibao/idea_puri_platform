package com.midea.william.ui
{
	
	import flash.display.MovieClip;
	import flash.text.TextField;
	import com.midea.william.PinFunOption;
	
	
	public class DevicePort extends MovieClip
	{
		public var des_txt:TextField;
		public var macro_txt:TextField;
		
		private var _macroTxt:String;
		private var _funOption:String;
		
		public function DevicePort(info:XML) 
		{
			des_txt.text = info.des;
			
			_macroTxt = info.macro;
			macro_txt.text = _macroTxt;
			
			_funOption = info.fun;
		}
		
		public function get macroTxt():String
		{
			return this._macroTxt;
		}
		
		public function get funOption():String
		{
			return this._funOption;
		}
	}
	
}
