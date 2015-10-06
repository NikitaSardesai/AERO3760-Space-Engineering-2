<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="gps">
<packages>
<package name="GPS">
<wire x1="1.27" y1="0" x2="16.51" y2="0" width="0.127" layer="21"/>
<pad name="SDA" x="2.54" y="1.27" drill="0.8" shape="square"/>
<pad name="SCL" x="5.08" y="1.27" drill="0.8" shape="square"/>
<pad name="TX" x="7.62" y="1.27" drill="0.8" shape="square"/>
<pad name="RX" x="10.16" y="1.27" drill="0.8" shape="square"/>
<pad name="GND" x="12.7" y="1.27" drill="0.8" shape="square"/>
<pad name="3.3V" x="15.24" y="1.27" drill="0.8" shape="square"/>
<wire x1="1.27" y1="0" x2="1.27" y2="29.21" width="0.127" layer="21"/>
<wire x1="16.51" y1="29.21" x2="16.51" y2="0" width="0.127" layer="21"/>
<wire x1="1.27" y1="29.21" x2="1.27" y2="34.29" width="0.127" layer="21"/>
<wire x1="1.27" y1="34.29" x2="16.51" y2="34.29" width="0.127" layer="21"/>
<wire x1="16.51" y1="34.29" x2="16.51" y2="29.21" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="GPS">
<wire x1="0" y1="0" x2="0" y2="25.4" width="0.254" layer="94"/>
<wire x1="0" y1="25.4" x2="17.78" y2="25.4" width="0.254" layer="94"/>
<wire x1="17.78" y1="25.4" x2="17.78" y2="0" width="0.254" layer="94"/>
<wire x1="17.78" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="SDA" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="SCL" x="5.08" y="-5.08" length="middle" rot="R90"/>
<pin name="TX" x="7.62" y="-5.08" length="middle" rot="R90"/>
<pin name="RX" x="10.16" y="-5.08" length="middle" rot="R90"/>
<pin name="GND" x="12.7" y="-5.08" length="middle" rot="R90"/>
<pin name="3.3V" x="15.24" y="-5.08" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GPS">
<gates>
<gate name="G$1" symbol="GPS" x="-7.62" y="-2.54"/>
</gates>
<devices>
<device name="" package="GPS">
<connects>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="imu">
<packages>
<package name="IMU">
<wire x1="0" y1="0" x2="0" y2="22.86" width="0.127" layer="21"/>
<wire x1="0" y1="22.86" x2="38.1" y2="22.86" width="0.127" layer="21"/>
<wire x1="38.1" y1="22.86" x2="38.1" y2="0" width="0.127" layer="21"/>
<wire x1="38.1" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<pad name="5V" x="7.62" y="2.54" drill="0.8" shape="square"/>
<pad name="3V" x="10.16" y="2.54" drill="0.8" shape="square"/>
<pad name="GND" x="12.7" y="2.54" drill="0.8" shape="square"/>
<pad name="SCL" x="15.24" y="2.54" drill="0.8" shape="square"/>
<pad name="SDA" x="17.78" y="2.54" drill="0.8" shape="square"/>
<pad name="GINT" x="20.32" y="2.54" drill="0.8" shape="square"/>
<pad name="GRDY" x="22.86" y="2.54" drill="0.8" shape="square"/>
<pad name="LINT1" x="25.4" y="2.54" drill="0.8" shape="square"/>
<pad name="LINT2" x="27.94" y="2.54" drill="0.8" shape="square"/>
<pad name="LRDY" x="30.48" y="2.54" drill="0.8" shape="square"/>
<hole x="2.54" y="2.54" drill="2.54"/>
<hole x="35.56" y="2.54" drill="2.54"/>
<hole x="2.54" y="20.32" drill="2.54"/>
<hole x="35.56" y="20.32" drill="2.54"/>
</package>
</packages>
<symbols>
<symbol name="IMU">
<wire x1="-33.02" y1="12.7" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="12.7" y2="-15.24" width="0.254" layer="94"/>
<wire x1="12.7" y1="-15.24" x2="-33.02" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-15.24" x2="-33.02" y2="12.7" width="0.254" layer="94"/>
<pin name="5V" x="-30.48" y="-20.32" length="middle" rot="R90"/>
<pin name="GND" x="-25.4" y="-20.32" length="middle" rot="R90"/>
<pin name="SCL" x="-20.32" y="-20.32" length="middle" rot="R90"/>
<pin name="SDA" x="-15.24" y="-20.32" length="middle" rot="R90"/>
<pin name="GINT" x="-10.16" y="-20.32" length="middle" rot="R90"/>
<pin name="GRDY" x="-5.08" y="-20.32" length="middle" rot="R90"/>
<pin name="LIN1" x="0" y="-20.32" length="middle" rot="R90"/>
<pin name="LIN2" x="5.08" y="-20.32" length="middle" rot="R90"/>
<pin name="LRDY" x="10.16" y="-20.32" length="middle" rot="R90"/>
<pin name="3V" x="-38.1" y="-5.08" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="IMU">
<gates>
<gate name="G$1" symbol="IMU" x="0" y="0"/>
</gates>
<devices>
<device name="" package="IMU">
<connects>
<connect gate="G$1" pin="3V" pad="3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="GINT" pad="GINT"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GRDY" pad="GRDY"/>
<connect gate="G$1" pin="LIN1" pad="LINT1"/>
<connect gate="G$1" pin="LIN2" pad="LINT2"/>
<connect gate="G$1" pin="LRDY" pad="LRDY"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2X08">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.905" x2="-9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="2.54" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="2.54" x2="7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="2.54" x2="10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="1.27" drill="1.016" shape="octagon"/>
<text x="-10.16" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
</package>
<package name="2X08/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-10.795" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="12.065" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-5.461" x2="-8.509" y2="-4.699" layer="21"/>
<rectangle x1="-9.271" y1="-4.699" x2="-8.509" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-4.699" x2="-5.969" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-5.461" x2="-5.969" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-5.461" x2="-3.429" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-4.699" x2="-3.429" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-4.699" x2="-0.889" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-5.461" x2="-0.889" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-5.461" x2="1.651" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-4.699" x2="1.651" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-4.699" x2="4.191" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-5.461" x2="4.191" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-5.461" x2="6.731" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-4.699" x2="6.731" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-4.699" x2="9.271" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-5.461" x2="9.271" y2="-4.699" layer="21"/>
</package>
<package name="1X02">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-2.6162" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
<package name="1X02/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-3.175" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.445" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PINH2X8">
<wire x1="-6.35" y1="-12.7" x2="8.89" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-12.7" x2="8.89" y2="10.16" width="0.4064" layer="94"/>
<wire x1="8.89" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-12.7" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="15" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="5.08" y="-10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
<symbol name="PINHD2">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-2X8" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X08">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X08/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X2" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X02">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X02/90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="hbridge">
<packages>
<package name="HBRIDGE">
<pad name="12EN" x="-6.35" y="-2.54" drill="0.8" shape="square"/>
<pad name="1A" x="-3.81" y="-2.54" drill="0.8" shape="square"/>
<pad name="1Y" x="-1.27" y="-2.54" drill="0.8" shape="square"/>
<pad name="P$4" x="1.27" y="-2.54" drill="0.8" shape="square"/>
<pad name="P$5" x="3.81" y="-2.54" drill="0.8" shape="square"/>
<pad name="2Y" x="6.35" y="-2.54" drill="0.8" shape="square"/>
<pad name="2A" x="8.89" y="-2.54" drill="0.8" shape="square"/>
<pad name="VCC2" x="11.43" y="-2.54" drill="0.8" shape="square"/>
<pad name="VCC1" x="-6.35" y="5.08" drill="0.8" shape="square"/>
<pad name="4A" x="-3.81" y="5.08" drill="0.8" shape="square"/>
<pad name="4Y" x="-1.27" y="5.08" drill="0.8" shape="square"/>
<pad name="P$12" x="1.27" y="5.08" drill="0.8" shape="square"/>
<pad name="P$13" x="3.81" y="5.08" drill="0.8" shape="square"/>
<pad name="3Y" x="6.35" y="5.08" drill="0.8" shape="square"/>
<pad name="3A" x="8.89" y="5.08" drill="0.8" shape="square"/>
<pad name="34EN" x="11.43" y="5.08" drill="0.8" shape="square"/>
<wire x1="-8.89" y1="3.81" x2="13.97" y2="3.81" width="0.127" layer="21"/>
<wire x1="13.97" y1="3.81" x2="13.97" y2="-1.27" width="0.127" layer="21"/>
<wire x1="13.97" y1="-1.27" x2="-8.89" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-1.27" x2="-8.89" y2="3.81" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="HBRIDGE">
<wire x1="-50.8" y1="17.78" x2="-5.08" y2="17.78" width="0.254" layer="94"/>
<wire x1="-5.08" y1="17.78" x2="-5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.62" x2="-50.8" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-50.8" y1="-7.62" x2="-50.8" y2="17.78" width="0.254" layer="94"/>
<pin name="12EN" x="-45.72" y="-12.7" length="middle" rot="R90"/>
<pin name="1A" x="-40.64" y="-12.7" length="middle" rot="R90"/>
<pin name="1Y" x="-35.56" y="-12.7" length="middle" rot="R90"/>
<pin name="HS1" x="-30.48" y="-12.7" length="middle" rot="R90"/>
<pin name="GND1" x="-25.4" y="-12.7" length="middle" rot="R90"/>
<pin name="2Y" x="-20.32" y="-12.7" length="middle" rot="R90"/>
<pin name="2A" x="-15.24" y="-12.7" length="middle" rot="R90"/>
<pin name="VCC2" x="-10.16" y="-12.7" length="middle" rot="R90"/>
<pin name="34EN" x="-10.16" y="22.86" length="middle" rot="R270"/>
<pin name="3A" x="-15.24" y="22.86" length="middle" rot="R270"/>
<pin name="3Y" x="-20.32" y="22.86" length="middle" rot="R270"/>
<pin name="GND2" x="-25.4" y="22.86" length="middle" rot="R270"/>
<pin name="HS2" x="-30.48" y="22.86" length="middle" rot="R270"/>
<pin name="4Y" x="-35.56" y="22.86" length="middle" rot="R270"/>
<pin name="4A" x="-40.64" y="22.86" length="middle" rot="R270"/>
<pin name="VCC1" x="-45.72" y="22.86" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="HBRIDGE">
<gates>
<gate name="G$1" symbol="HBRIDGE" x="27.94" y="-5.08"/>
</gates>
<devices>
<device name="" package="HBRIDGE">
<connects>
<connect gate="G$1" pin="12EN" pad="12EN"/>
<connect gate="G$1" pin="1A" pad="1A"/>
<connect gate="G$1" pin="1Y" pad="1Y"/>
<connect gate="G$1" pin="2A" pad="2A"/>
<connect gate="G$1" pin="2Y" pad="2Y"/>
<connect gate="G$1" pin="34EN" pad="34EN"/>
<connect gate="G$1" pin="3A" pad="3A"/>
<connect gate="G$1" pin="3Y" pad="3Y"/>
<connect gate="G$1" pin="4A" pad="4A"/>
<connect gate="G$1" pin="4Y" pad="4Y"/>
<connect gate="G$1" pin="GND1" pad="P$5"/>
<connect gate="G$1" pin="GND2" pad="P$12"/>
<connect gate="G$1" pin="HS1" pad="P$4"/>
<connect gate="G$1" pin="HS2" pad="P$13"/>
<connect gate="G$1" pin="VCC1" pad="VCC1"/>
<connect gate="G$1" pin="VCC2" pad="VCC2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="gps" deviceset="GPS" device=""/>
<part name="U$2" library="imu" deviceset="IMU" device=""/>
<part name="JP1" library="pinhead" deviceset="PINHD-2X8" device=""/>
<part name="U$3" library="hbridge" deviceset="HBRIDGE" device=""/>
<part name="U$4" library="hbridge" deviceset="HBRIDGE" device=""/>
<part name="H" library="pinhead" deviceset="PINHD-2X8" device=""/>
<part name="MAG1" library="pinhead" deviceset="PINHD-1X2" device=""/>
<part name="MAG2" library="pinhead" deviceset="PINHD-1X2" device=""/>
<part name="MAG3" library="pinhead" deviceset="PINHD-1X2" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-5.08" y="-5.08"/>
<instance part="U$2" gate="G$1" x="78.74" y="-10.16"/>
<instance part="JP1" gate="A" x="-43.18" y="-45.72"/>
<instance part="U$3" gate="G$1" x="-66.04" y="-124.46" rot="R270"/>
<instance part="U$4" gate="G$1" x="50.8" y="-124.46" rot="R270"/>
<instance part="H" gate="A" x="-58.42" y="-149.86"/>
<instance part="MAG1" gate="G$1" x="-127" y="-99.06"/>
<instance part="MAG2" gate="G$1" x="-2.54" y="-91.44"/>
<instance part="MAG3" gate="G$1" x="5.08" y="-104.14"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="-45.72" y1="-38.1" x2="-53.34" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-38.1" x2="-53.34" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="3.3V"/>
<wire x1="-53.34" y1="-30.48" x2="10.16" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-30.48" x2="10.16" y2="-15.24" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="3V"/>
<wire x1="10.16" y1="-15.24" x2="10.16" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="40.64" y1="-15.24" x2="10.16" y2="-15.24" width="0.1524" layer="91"/>
<junction x="10.16" y="-15.24"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="7.62" y1="-27.94" x2="-2.54" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="-27.94" x2="-55.88" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-55.88" y1="-27.94" x2="-55.88" y2="-40.64" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="3"/>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="-55.88" y1="-40.64" x2="-45.72" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="53.34" y1="-30.48" x2="53.34" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="53.34" y1="-35.56" x2="-2.54" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="-35.56" x2="-2.54" y2="-27.94" width="0.1524" layer="91"/>
<junction x="-2.54" y="-27.94"/>
<wire x1="-55.88" y1="-40.64" x2="-81.28" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-40.64" x2="-81.28" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="-99.06" x2="-81.28" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-99.06" x2="-81.28" y2="-93.98" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="HS1"/>
<wire x1="-81.28" y1="-93.98" x2="-78.74" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-99.06" x2="-81.28" y2="-101.6" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-101.6" x2="-38.1" y2="-101.6" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="-101.6" x2="-38.1" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="-93.98" x2="-43.18" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-93.98" x2="-38.1" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="-93.98" x2="-38.1" y2="-99.06" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="GND2"/>
<wire x1="-38.1" y1="-99.06" x2="-43.18" y2="-99.06" width="0.1524" layer="91"/>
<junction x="-81.28" y="-93.98"/>
<junction x="-81.28" y="-99.06"/>
<junction x="-38.1" y="-99.06"/>
<wire x1="-38.1" y1="-99.06" x2="-33.02" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="-99.06" x2="-33.02" y2="-142.24" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="HS2"/>
<pinref part="U$4" gate="G$1" pin="GND2"/>
<pinref part="U$4" gate="G$1" pin="HS1"/>
<wire x1="25.4" y1="-93.98" x2="38.1" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-99.06" x2="25.4" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-99.06" x2="38.1" y2="-99.06" width="0.1524" layer="91"/>
<junction x="25.4" y="-99.06"/>
<wire x1="38.1" y1="-99.06" x2="40.64" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-134.62" x2="25.4" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-134.62" x2="86.36" y2="-134.62" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-134.62" x2="86.36" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-99.06" x2="73.66" y2="-99.06" width="0.1524" layer="91"/>
<junction x="86.36" y="-99.06"/>
<wire x1="86.36" y1="-99.06" x2="86.36" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-93.98" x2="73.66" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="-142.24" x2="86.36" y2="-142.24" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-142.24" x2="86.36" y2="-134.62" width="0.1524" layer="91"/>
<junction x="86.36" y="-134.62"/>
<junction x="-55.88" y="-40.64"/>
<pinref part="U$3" gate="G$1" pin="HS2"/>
<junction x="-43.18" y="-93.98"/>
<junction x="-43.18" y="-99.06"/>
<junction x="38.1" y="-93.98"/>
<pinref part="U$4" gate="G$1" pin="GND1"/>
<junction x="38.1" y="-99.06"/>
<junction x="73.66" y="-99.06"/>
<junction x="73.66" y="-93.98"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RX"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="5.08" y1="-25.4" x2="-58.42" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="-58.42" y1="-25.4" x2="-58.42" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="-58.42" y1="-43.18" x2="-45.72" y2="-43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="TX"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="2.54" y1="-22.86" x2="-60.96" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="-22.86" x2="-60.96" y2="-45.72" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="7"/>
<wire x1="-60.96" y1="-45.72" x2="-45.72" y2="-45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="SCL"/>
<wire x1="0" y1="-10.16" x2="0" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="0" y1="-20.32" x2="-63.5" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="-20.32" x2="-63.5" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="9"/>
<wire x1="-63.5" y1="-48.26" x2="-45.72" y2="-48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="SDA"/>
<wire x1="-2.54" y1="-10.16" x2="-2.54" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="-17.78" x2="-66.04" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-66.04" y1="-17.78" x2="-66.04" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="11"/>
<wire x1="-66.04" y1="-50.8" x2="-45.72" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="LRDY"/>
<wire x1="88.9" y1="-30.48" x2="88.9" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="88.9" y1="-71.12" x2="-66.04" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="-66.04" y1="-71.12" x2="-66.04" y2="-53.34" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="13"/>
<wire x1="-66.04" y1="-53.34" x2="-45.72" y2="-53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="LIN2"/>
<wire x1="83.82" y1="-30.48" x2="83.82" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="83.82" y1="-68.58" x2="-63.5" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="-68.58" x2="-63.5" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="15"/>
<wire x1="-63.5" y1="-55.88" x2="-45.72" y2="-55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="LIN1"/>
<wire x1="78.74" y1="-30.48" x2="78.74" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-58.42" x2="-30.48" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="-58.42" x2="-30.48" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="16"/>
<wire x1="-30.48" y1="-55.88" x2="-38.1" y2="-55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="JP1" gate="A" pin="14"/>
<pinref part="U$2" gate="G$1" pin="GRDY"/>
<wire x1="-38.1" y1="-53.34" x2="73.66" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-53.34" x2="73.66" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="JP1" gate="A" pin="12"/>
<pinref part="U$2" gate="G$1" pin="GINT"/>
<wire x1="-38.1" y1="-50.8" x2="68.58" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="68.58" y1="-50.8" x2="68.58" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="JP1" gate="A" pin="10"/>
<pinref part="U$2" gate="G$1" pin="SDA"/>
<wire x1="-38.1" y1="-48.26" x2="63.5" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="63.5" y1="-48.26" x2="63.5" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="JP1" gate="A" pin="8"/>
<pinref part="U$2" gate="G$1" pin="SCL"/>
<wire x1="-38.1" y1="-45.72" x2="58.42" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="58.42" y1="-45.72" x2="58.42" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<wire x1="-76.2" y1="-78.74" x2="-78.74" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-78.74" x2="-111.76" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="-78.74" x2="-111.76" y2="-142.24" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="-142.24" x2="-60.96" y2="-142.24" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="1"/>
<pinref part="U$3" gate="G$1" pin="12EN"/>
<junction x="-78.74" y="-78.74"/>
<junction x="-60.96" y="-142.24"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<wire x1="-60.96" y1="-144.78" x2="-86.36" y2="-144.78" width="0.1524" layer="91"/>
<wire x1="-86.36" y1="-144.78" x2="-86.36" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="-86.36" y1="-83.82" x2="-78.74" y2="-83.82" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="3"/>
<pinref part="U$3" gate="G$1" pin="1A"/>
<junction x="-78.74" y="-83.82"/>
<wire x1="-78.74" y1="-83.82" x2="-76.2" y2="-83.82" width="0.1524" layer="91"/>
<junction x="-60.96" y="-144.78"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<wire x1="-38.1" y1="-142.24" x2="-38.1" y2="-114.3" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="-114.3" x2="-43.18" y2="-114.3" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="2"/>
<wire x1="-43.18" y1="-114.3" x2="-45.72" y2="-114.3" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-142.24" x2="-38.1" y2="-142.24" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="34EN"/>
<junction x="-43.18" y="-114.3"/>
<junction x="-53.34" y="-142.24"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="3A"/>
<wire x1="-43.18" y1="-109.22" x2="-22.86" y2="-109.22" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-109.22" x2="-22.86" y2="-144.78" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="4"/>
<wire x1="-22.86" y1="-144.78" x2="-53.34" y2="-144.78" width="0.1524" layer="91"/>
<junction x="-43.18" y="-109.22"/>
<junction x="-53.34" y="-144.78"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<wire x1="10.16" y1="-149.86" x2="10.16" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-78.74" x2="38.1" y2="-78.74" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="8"/>
<wire x1="38.1" y1="-78.74" x2="40.64" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-149.86" x2="10.16" y2="-149.86" width="0.1524" layer="91"/>
<junction x="-53.34" y="-149.86"/>
<pinref part="U$4" gate="G$1" pin="12EN"/>
<junction x="38.1" y="-78.74"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<wire x1="40.64" y1="-83.82" x2="38.1" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="38.1" y1="-83.82" x2="12.7" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-83.82" x2="12.7" y2="-152.4" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="10"/>
<wire x1="12.7" y1="-152.4" x2="-53.34" y2="-152.4" width="0.1524" layer="91"/>
<junction x="-53.34" y="-152.4"/>
<pinref part="U$4" gate="G$1" pin="1A"/>
<junction x="38.1" y="-83.82"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VCC2"/>
<wire x1="-78.74" y1="-114.3" x2="-81.28" y2="-114.3" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-114.3" x2="-81.28" y2="-124.46" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-124.46" x2="-7.62" y2="-124.46" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="-124.46" x2="-7.62" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="-38.1" x2="-25.4" y2="-63.5" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="-63.5" x2="-25.4" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="-78.74" x2="-43.18" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-78.74" x2="-45.72" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="-63.5" x2="78.74" y2="-63.5" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-63.5" x2="78.74" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-78.74" x2="73.66" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-78.74" x2="71.12" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-78.74" x2="78.74" y2="-121.92" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-121.92" x2="35.56" y2="-121.92" width="0.1524" layer="91"/>
<wire x1="35.56" y1="-121.92" x2="35.56" y2="-114.3" width="0.1524" layer="91"/>
<wire x1="35.56" y1="-114.3" x2="38.1" y2="-114.3" width="0.1524" layer="91"/>
<junction x="78.74" y="-78.74"/>
<junction x="-25.4" y="-63.5"/>
<wire x1="38.1" y1="-114.3" x2="40.64" y2="-114.3" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="-78.74" x2="-25.4" y2="-78.74" width="0.1524" layer="91"/>
<junction x="-25.4" y="-78.74"/>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="-38.1" y1="-38.1" x2="-25.4" y2="-38.1" width="0.1524" layer="91"/>
<junction x="-78.74" y="-114.3"/>
<pinref part="U$3" gate="G$1" pin="VCC1"/>
<junction x="-43.18" y="-78.74"/>
<pinref part="U$4" gate="G$1" pin="VCC2"/>
<junction x="38.1" y="-114.3"/>
<pinref part="U$4" gate="G$1" pin="VCC1"/>
<junction x="73.66" y="-78.74"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="2A"/>
<wire x1="-78.74" y1="-109.22" x2="-83.82" y2="-109.22" width="0.1524" layer="91"/>
<wire x1="-83.82" y1="-109.22" x2="-83.82" y2="-147.32" width="0.1524" layer="91"/>
<pinref part="H" gate="A" pin="5"/>
<wire x1="-83.82" y1="-147.32" x2="-60.96" y2="-147.32" width="0.1524" layer="91"/>
<junction x="-78.74" y="-109.22"/>
<junction x="-60.96" y="-147.32"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="H" gate="A" pin="6"/>
<wire x1="-53.34" y1="-147.32" x2="-20.32" y2="-147.32" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="-147.32" x2="-20.32" y2="-83.82" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="4A"/>
<wire x1="-20.32" y1="-83.82" x2="-43.18" y2="-83.82" width="0.1524" layer="91"/>
<junction x="-43.18" y="-83.82"/>
<junction x="-53.34" y="-147.32"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="H" gate="A" pin="12"/>
<wire x1="-53.34" y1="-154.94" x2="15.24" y2="-154.94" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-154.94" x2="15.24" y2="-109.22" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="2A"/>
<wire x1="15.24" y1="-109.22" x2="38.1" y2="-109.22" width="0.1524" layer="91"/>
<junction x="-53.34" y="-154.94"/>
<junction x="38.1" y="-109.22"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<wire x1="-76.2" y1="-88.9" x2="-78.74" y2="-88.9" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-88.9" x2="-121.92" y2="-88.9" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="-88.9" x2="-121.92" y2="-96.52" width="0.1524" layer="91"/>
<pinref part="MAG1" gate="G$1" pin="1"/>
<wire x1="-121.92" y1="-96.52" x2="-129.54" y2="-96.52" width="0.1524" layer="91"/>
<junction x="-129.54" y="-96.52"/>
<pinref part="U$3" gate="G$1" pin="1Y"/>
<junction x="-78.74" y="-88.9"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="MAG1" gate="G$1" pin="2"/>
<wire x1="-129.54" y1="-99.06" x2="-121.92" y2="-99.06" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="-99.06" x2="-121.92" y2="-104.14" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="2Y"/>
<wire x1="-121.92" y1="-104.14" x2="-78.74" y2="-104.14" width="0.1524" layer="91"/>
<junction x="-129.54" y="-99.06"/>
<junction x="-78.74" y="-104.14"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="4Y"/>
<wire x1="-43.18" y1="-88.9" x2="-5.08" y2="-88.9" width="0.1524" layer="91"/>
<pinref part="MAG2" gate="G$1" pin="1"/>
<junction x="-43.18" y="-88.9"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="3Y"/>
<wire x1="-43.18" y1="-104.14" x2="-12.7" y2="-104.14" width="0.1524" layer="91"/>
<wire x1="-12.7" y1="-104.14" x2="-12.7" y2="-91.44" width="0.1524" layer="91"/>
<pinref part="MAG2" gate="G$1" pin="2"/>
<wire x1="-12.7" y1="-91.44" x2="-5.08" y2="-91.44" width="0.1524" layer="91"/>
<junction x="-43.18" y="-104.14"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="1Y"/>
<wire x1="38.1" y1="-88.9" x2="7.62" y2="-88.9" width="0.1524" layer="91"/>
<wire x1="7.62" y1="-88.9" x2="7.62" y2="-101.6" width="0.1524" layer="91"/>
<pinref part="MAG3" gate="G$1" pin="1"/>
<wire x1="7.62" y1="-101.6" x2="2.54" y2="-101.6" width="0.1524" layer="91"/>
<junction x="38.1" y="-88.9"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="MAG3" gate="G$1" pin="2"/>
<pinref part="U$4" gate="G$1" pin="2Y"/>
<wire x1="2.54" y1="-104.14" x2="38.1" y2="-104.14" width="0.1524" layer="91"/>
<junction x="38.1" y="-104.14"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
