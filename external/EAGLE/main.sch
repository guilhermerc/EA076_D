<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
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
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="FRDM">
<description>Library for the Freescale Freedom FRDM-KL25Z Board</description>
<packages>
<package name="FRDM_KL25Z_NORMAL">
<wire x1="24.765" y1="19.05" x2="23.495" y2="19.05" width="0.127" layer="21"/>
<wire x1="24.765" y1="19.05" x2="25.4" y2="18.415" width="0.127" layer="21"/>
<wire x1="23.495" y1="19.05" x2="22.86" y2="18.415" width="0.127" layer="21"/>
<wire x1="25.4" y1="18.415" x2="25.4" y2="17.145" width="0.127" layer="21"/>
<wire x1="25.4" y1="17.145" x2="24.765" y2="16.51" width="0.127" layer="21"/>
<wire x1="24.765" y1="16.51" x2="25.4" y2="15.875" width="0.127" layer="21"/>
<wire x1="25.4" y1="15.875" x2="25.4" y2="14.605" width="0.127" layer="21"/>
<wire x1="25.4" y1="14.605" x2="24.765" y2="13.97" width="0.127" layer="21"/>
<wire x1="24.765" y1="13.97" x2="25.4" y2="13.335" width="0.127" layer="21"/>
<wire x1="25.4" y1="13.335" x2="25.4" y2="12.065" width="0.127" layer="21"/>
<wire x1="25.4" y1="12.065" x2="24.765" y2="11.43" width="0.127" layer="21"/>
<wire x1="24.765" y1="11.43" x2="25.4" y2="10.795" width="0.127" layer="21"/>
<wire x1="25.4" y1="10.795" x2="25.4" y2="9.525" width="0.127" layer="21"/>
<wire x1="25.4" y1="9.525" x2="24.765" y2="8.89" width="0.127" layer="21"/>
<wire x1="24.765" y1="8.89" x2="25.4" y2="8.255" width="0.127" layer="21"/>
<wire x1="25.4" y1="8.255" x2="25.4" y2="6.985" width="0.127" layer="21"/>
<wire x1="25.4" y1="6.985" x2="24.765" y2="6.35" width="0.127" layer="21"/>
<wire x1="24.765" y1="6.35" x2="25.4" y2="5.715" width="0.127" layer="21"/>
<wire x1="25.4" y1="5.715" x2="25.4" y2="4.445" width="0.127" layer="21"/>
<wire x1="25.4" y1="4.445" x2="24.765" y2="3.81" width="0.127" layer="21"/>
<wire x1="24.765" y1="3.81" x2="23.495" y2="3.81" width="0.127" layer="21"/>
<wire x1="20.955" y1="1.27" x2="20.32" y2="0.635" width="0.127" layer="21"/>
<wire x1="20.32" y1="0.635" x2="20.32" y2="-0.635" width="0.127" layer="21"/>
<wire x1="20.32" y1="-0.635" x2="20.955" y2="-1.27" width="0.127" layer="21"/>
<wire x1="20.955" y1="-1.27" x2="20.32" y2="-1.905" width="0.127" layer="21"/>
<wire x1="20.32" y1="-1.905" x2="20.32" y2="-3.175" width="0.127" layer="21"/>
<wire x1="20.32" y1="-3.175" x2="20.955" y2="-3.81" width="0.127" layer="21"/>
<wire x1="20.955" y1="-3.81" x2="20.32" y2="-4.445" width="0.127" layer="21"/>
<wire x1="20.32" y1="-4.445" x2="20.32" y2="-5.715" width="0.127" layer="21"/>
<wire x1="20.32" y1="-5.715" x2="20.955" y2="-6.35" width="0.127" layer="21"/>
<wire x1="20.955" y1="-6.35" x2="20.32" y2="-6.985" width="0.127" layer="21"/>
<wire x1="20.32" y1="-8.255" x2="20.955" y2="-8.89" width="0.127" layer="21"/>
<wire x1="20.955" y1="-8.89" x2="20.32" y2="-9.525" width="0.127" layer="21"/>
<wire x1="20.32" y1="-9.525" x2="20.32" y2="-10.795" width="0.127" layer="21"/>
<wire x1="20.32" y1="-10.795" x2="20.955" y2="-11.43" width="0.127" layer="21"/>
<wire x1="20.955" y1="-11.43" x2="20.32" y2="-12.065" width="0.127" layer="21"/>
<wire x1="20.32" y1="-18.415" x2="20.955" y2="-19.05" width="0.127" layer="21"/>
<wire x1="24.765" y1="-19.05" x2="25.4" y2="-18.415" width="0.127" layer="21"/>
<wire x1="25.4" y1="-12.065" x2="24.765" y2="-11.43" width="0.127" layer="21"/>
<wire x1="24.765" y1="-11.43" x2="25.4" y2="-10.795" width="0.127" layer="21"/>
<wire x1="25.4" y1="-10.795" x2="25.4" y2="-9.525" width="0.127" layer="21"/>
<wire x1="25.4" y1="-9.525" x2="24.765" y2="-8.89" width="0.127" layer="21"/>
<wire x1="24.765" y1="-8.89" x2="25.4" y2="-8.255" width="0.127" layer="21"/>
<wire x1="25.4" y1="-8.255" x2="25.4" y2="-6.985" width="0.127" layer="21"/>
<wire x1="25.4" y1="-6.985" x2="24.765" y2="-6.35" width="0.127" layer="21"/>
<wire x1="24.765" y1="-6.35" x2="25.4" y2="-5.715" width="0.127" layer="21"/>
<wire x1="25.4" y1="-5.715" x2="25.4" y2="-4.445" width="0.127" layer="21"/>
<wire x1="25.4" y1="-4.445" x2="24.765" y2="-3.81" width="0.127" layer="21"/>
<wire x1="24.765" y1="-3.81" x2="25.4" y2="-3.175" width="0.127" layer="21"/>
<wire x1="25.4" y1="-3.175" x2="25.4" y2="-1.905" width="0.127" layer="21"/>
<wire x1="25.4" y1="-1.905" x2="24.765" y2="-1.27" width="0.127" layer="21"/>
<wire x1="24.765" y1="-1.27" x2="25.4" y2="-0.635" width="0.127" layer="21"/>
<wire x1="25.4" y1="-0.635" x2="25.4" y2="0.635" width="0.127" layer="21"/>
<wire x1="25.4" y1="0.635" x2="24.765" y2="1.27" width="0.127" layer="21"/>
<wire x1="-23.495" y1="19.05" x2="-24.765" y2="19.05" width="0.127" layer="21"/>
<wire x1="-24.765" y1="19.05" x2="-25.4" y2="18.415" width="0.127" layer="21"/>
<wire x1="-25.4" y1="18.415" x2="-25.4" y2="17.145" width="0.127" layer="21"/>
<wire x1="-25.4" y1="17.145" x2="-24.765" y2="16.51" width="0.127" layer="21"/>
<wire x1="-24.765" y1="16.51" x2="-25.4" y2="15.875" width="0.127" layer="21"/>
<wire x1="-25.4" y1="15.875" x2="-25.4" y2="14.605" width="0.127" layer="21"/>
<wire x1="-25.4" y1="14.605" x2="-24.765" y2="13.97" width="0.127" layer="21"/>
<wire x1="-24.765" y1="13.97" x2="-25.4" y2="13.335" width="0.127" layer="21"/>
<wire x1="-25.4" y1="13.335" x2="-25.4" y2="12.065" width="0.127" layer="21"/>
<wire x1="-25.4" y1="12.065" x2="-24.765" y2="11.43" width="0.127" layer="21"/>
<wire x1="-24.765" y1="11.43" x2="-25.4" y2="10.795" width="0.127" layer="21"/>
<wire x1="-25.4" y1="10.795" x2="-25.4" y2="9.525" width="0.127" layer="21"/>
<wire x1="-25.4" y1="9.525" x2="-24.765" y2="8.89" width="0.127" layer="21"/>
<wire x1="-24.765" y1="8.89" x2="-25.4" y2="8.255" width="0.127" layer="21"/>
<wire x1="-25.4" y1="8.255" x2="-25.4" y2="6.985" width="0.127" layer="21"/>
<wire x1="-25.4" y1="6.985" x2="-24.765" y2="6.35" width="0.127" layer="21"/>
<wire x1="-24.765" y1="6.35" x2="-25.4" y2="5.715" width="0.127" layer="21"/>
<wire x1="-25.4" y1="5.715" x2="-25.4" y2="4.445" width="0.127" layer="21"/>
<wire x1="-25.4" y1="4.445" x2="-24.765" y2="3.81" width="0.127" layer="21"/>
<wire x1="-24.765" y1="3.81" x2="-25.4" y2="3.175" width="0.127" layer="21"/>
<wire x1="-25.4" y1="3.175" x2="-25.4" y2="1.905" width="0.127" layer="21"/>
<wire x1="-25.4" y1="1.905" x2="-24.765" y2="1.27" width="0.127" layer="21"/>
<wire x1="-24.765" y1="1.27" x2="-25.4" y2="0.635" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-0.635" x2="-24.765" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-1.27" x2="-23.495" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-23.495" y1="-1.27" x2="-22.86" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-22.86" y1="18.415" x2="-23.495" y2="19.05" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-2.54" x2="-25.4" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-3.175" x2="-25.4" y2="-4.445" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-4.445" x2="-24.765" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-5.08" x2="-25.4" y2="-5.715" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-5.715" x2="-25.4" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-6.985" x2="-24.765" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-7.62" x2="-25.4" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-8.255" x2="-25.4" y2="-9.525" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-9.525" x2="-24.765" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-10.16" x2="-25.4" y2="-10.795" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-10.795" x2="-25.4" y2="-12.065" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-12.065" x2="-24.765" y2="-12.7" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-12.7" x2="-25.4" y2="-13.335" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-13.335" x2="-25.4" y2="-14.605" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-14.605" x2="-24.765" y2="-15.24" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-15.24" x2="-25.4" y2="-15.875" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-15.875" x2="-25.4" y2="-17.145" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-17.145" x2="-24.765" y2="-17.78" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-17.78" x2="-25.4" y2="-18.415" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-18.415" x2="-25.4" y2="-19.685" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-19.685" x2="-24.765" y2="-20.32" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-20.32" x2="-25.4" y2="-20.955" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-27.305" x2="-24.765" y2="-27.94" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-27.94" x2="-20.32" y2="-27.305" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-20.955" x2="-20.955" y2="-20.32" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-20.32" x2="-20.32" y2="-19.685" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-19.685" x2="-20.32" y2="-18.415" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-18.415" x2="-20.955" y2="-17.78" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-17.78" x2="-20.32" y2="-17.145" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-17.145" x2="-20.32" y2="-15.875" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-15.875" x2="-20.955" y2="-15.24" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-15.24" x2="-20.32" y2="-14.605" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-14.605" x2="-20.32" y2="-13.335" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-13.335" x2="-20.955" y2="-12.7" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-12.7" x2="-20.32" y2="-12.065" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-12.065" x2="-20.32" y2="-10.795" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-10.795" x2="-20.955" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-10.16" x2="-20.32" y2="-9.525" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-9.525" x2="-20.32" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-8.255" x2="-20.955" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-7.62" x2="-20.32" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-6.985" x2="-20.32" y2="-5.715" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-5.715" x2="-20.955" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-5.08" x2="-20.32" y2="-4.445" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-4.445" x2="-20.32" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-3.175" x2="-20.955" y2="-2.54" width="0.127" layer="21"/>
<text x="25.654" y="-4.191" size="0.6096" layer="21" rot="R270">GND</text>
<text x="25.654" y="-1.651" size="0.6096" layer="21" rot="R270">GND</text>
<text x="25.654" y="0.889" size="0.6096" layer="21" rot="R270">VIN</text>
<text x="25.654" y="-6.985" size="0.6096" layer="21" rot="R270">5V</text>
<text x="25.654" y="-9.271" size="0.6096" layer="21" rot="R270">3V3</text>
<text x="25.654" y="-11.811" size="0.6096" layer="21" rot="R270">RES</text>
<text x="25.654" y="5.715" size="0.6096" layer="21" rot="R270">A0</text>
<text x="25.654" y="8.255" size="0.6096" layer="21" rot="R270">A1</text>
<text x="25.654" y="10.795" size="0.6096" layer="21" rot="R270">A2</text>
<text x="25.654" y="13.335" size="0.6096" layer="21" rot="R270">A3</text>
<text x="25.654" y="15.875" size="0.6096" layer="21" rot="R270">A4</text>
<text x="25.654" y="18.415" size="0.6096" layer="21" rot="R270">A5</text>
<text x="-25.654" y="18.415" size="0.6096" layer="21" rot="R90" align="bottom-right">D0</text>
<text x="-25.654" y="15.875" size="0.6096" layer="21" rot="R90" align="bottom-right">D1</text>
<text x="-25.654" y="13.335" size="0.6096" layer="21" rot="R90" align="bottom-right">D2</text>
<text x="-25.654" y="10.795" size="0.6096" layer="21" rot="R90" align="bottom-right">D3</text>
<text x="-25.654" y="8.255" size="0.6096" layer="21" rot="R90" align="bottom-right">D4</text>
<text x="-25.654" y="5.715" size="0.6096" layer="21" rot="R90" align="bottom-right">D5</text>
<text x="-25.654" y="3.175" size="0.6096" layer="21" rot="R90" align="bottom-right">D6</text>
<text x="-25.654" y="0.635" size="0.6096" layer="21" rot="R90" align="bottom-right">D7</text>
<text x="-25.654" y="-3.175" size="0.6096" layer="21" rot="R90" align="bottom-right">D8</text>
<text x="-25.654" y="-5.715" size="0.6096" layer="21" rot="R90" align="bottom-right">D9</text>
<text x="-25.654" y="-8.001" size="0.6096" layer="21" rot="R90" align="bottom-right">D10</text>
<text x="-25.654" y="-10.541" size="0.6096" layer="21" rot="R90" align="bottom-right">D11</text>
<text x="-25.654" y="-13.081" size="0.6096" layer="21" rot="R90" align="bottom-right">D12</text>
<text x="-25.654" y="-15.621" size="0.6096" layer="21" rot="R90" align="bottom-right">D13</text>
<text x="22.86" y="19.685" size="0.6096" layer="21" align="bottom-center">&gt;NAME</text>
<text x="-25.654" y="-18.161" size="0.6096" layer="21" rot="R90" align="bottom-right">GND</text>
<wire x1="-20.955" y1="19.05" x2="-22.225" y2="19.05" width="0.127" layer="21"/>
<wire x1="-22.225" y1="19.05" x2="-22.86" y2="18.415" width="0.127" layer="21"/>
<wire x1="-25.4" y1="0.635" x2="-25.4" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-22.86" y1="-0.635" x2="-22.225" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-22.225" y1="-1.27" x2="-20.955" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-1.27" x2="-20.32" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-0.635" x2="-20.32" y2="0.635" width="0.127" layer="21"/>
<wire x1="-20.32" y1="0.635" x2="-20.955" y2="1.27" width="0.127" layer="21"/>
<wire x1="-20.955" y1="1.27" x2="-20.32" y2="1.905" width="0.127" layer="21"/>
<wire x1="-20.32" y1="1.905" x2="-20.32" y2="3.175" width="0.127" layer="21"/>
<wire x1="-20.32" y1="3.175" x2="-20.955" y2="3.81" width="0.127" layer="21"/>
<wire x1="-20.955" y1="3.81" x2="-20.32" y2="4.445" width="0.127" layer="21"/>
<wire x1="-20.32" y1="4.445" x2="-20.32" y2="5.715" width="0.127" layer="21"/>
<wire x1="-20.32" y1="5.715" x2="-20.955" y2="6.35" width="0.127" layer="21"/>
<wire x1="-20.955" y1="6.35" x2="-20.32" y2="6.985" width="0.127" layer="21"/>
<wire x1="-20.32" y1="6.985" x2="-20.32" y2="8.255" width="0.127" layer="21"/>
<wire x1="-20.32" y1="8.255" x2="-20.955" y2="8.89" width="0.127" layer="21"/>
<wire x1="-20.955" y1="8.89" x2="-20.32" y2="9.525" width="0.127" layer="21"/>
<wire x1="-20.32" y1="9.525" x2="-20.32" y2="10.795" width="0.127" layer="21"/>
<wire x1="-20.32" y1="10.795" x2="-20.955" y2="11.43" width="0.127" layer="21"/>
<wire x1="-20.955" y1="11.43" x2="-20.32" y2="12.065" width="0.127" layer="21"/>
<wire x1="-20.32" y1="12.065" x2="-20.32" y2="13.335" width="0.127" layer="21"/>
<wire x1="-20.32" y1="13.335" x2="-20.955" y2="13.97" width="0.127" layer="21"/>
<wire x1="-20.955" y1="13.97" x2="-20.32" y2="14.605" width="0.127" layer="21"/>
<wire x1="-20.32" y1="14.605" x2="-20.32" y2="15.875" width="0.127" layer="21"/>
<wire x1="-20.32" y1="15.875" x2="-20.955" y2="16.51" width="0.127" layer="21"/>
<wire x1="-20.955" y1="16.51" x2="-20.32" y2="17.145" width="0.127" layer="21"/>
<wire x1="-20.32" y1="17.145" x2="-20.32" y2="18.415" width="0.127" layer="21"/>
<wire x1="-20.32" y1="18.415" x2="-20.955" y2="19.05" width="0.127" layer="21"/>
<text x="-20.066" y="18.415" size="0.6096" layer="21" rot="R270">C7</text>
<text x="-20.066" y="15.875" size="0.6096" layer="21" rot="R270">C0</text>
<text x="-20.066" y="13.335" size="0.6096" layer="21" rot="R270">C3</text>
<text x="-20.066" y="10.795" size="0.6096" layer="21" rot="R270">C4</text>
<text x="-20.066" y="8.255" size="0.6096" layer="21" rot="R270">C5</text>
<text x="-20.066" y="5.715" size="0.6096" layer="21" rot="R270">C6</text>
<text x="-20.066" y="3.429" size="0.6096" layer="21" rot="R270">C10</text>
<text x="-20.066" y="0.889" size="0.6096" layer="21" rot="R270">C11</text>
<pad name="PTC11" x="-21.59" y="0" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC10" x="-21.59" y="2.54" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC6" x="-21.59" y="5.08" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC5" x="-21.59" y="7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC4" x="-21.59" y="10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC3" x="-21.59" y="12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC0" x="-21.59" y="15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC7" x="-21.59" y="17.78" drill="0.9" shape="square" rot="R180"/>
<pad name="A0" x="24.13" y="5.08" drill="0.9" shape="square" rot="R180"/>
<pad name="A1" x="24.13" y="7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="A2" x="24.13" y="10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="A3" x="24.13" y="12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="A4" x="24.13" y="15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="A5" x="24.13" y="17.78" drill="0.9" shape="square" rot="R180"/>
<pad name="D7" x="-24.13" y="0" drill="0.9" shape="square" rot="R180"/>
<pad name="D6" x="-24.13" y="2.54" drill="0.9" shape="square" rot="R180"/>
<pad name="D5" x="-24.13" y="5.08" drill="0.9" shape="square" rot="R180"/>
<pad name="D4" x="-24.13" y="7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="D3" x="-24.13" y="10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="D2" x="-24.13" y="12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="D1" x="-24.13" y="15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="D0" x="-24.13" y="17.78" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE20" x="21.59" y="5.08" drill="0.9" shape="square" rot="R180"/>
<wire x1="22.225" y1="19.05" x2="20.955" y2="19.05" width="0.127" layer="21"/>
<wire x1="20.955" y1="19.05" x2="20.32" y2="18.415" width="0.127" layer="21"/>
<wire x1="20.32" y1="18.415" x2="20.32" y2="17.145" width="0.127" layer="21"/>
<wire x1="20.32" y1="17.145" x2="20.955" y2="16.51" width="0.127" layer="21"/>
<wire x1="20.955" y1="16.51" x2="20.32" y2="15.875" width="0.127" layer="21"/>
<wire x1="20.32" y1="15.875" x2="20.32" y2="14.605" width="0.127" layer="21"/>
<wire x1="20.32" y1="14.605" x2="20.955" y2="13.97" width="0.127" layer="21"/>
<wire x1="20.955" y1="13.97" x2="20.32" y2="13.335" width="0.127" layer="21"/>
<wire x1="20.32" y1="13.335" x2="20.32" y2="12.065" width="0.127" layer="21"/>
<wire x1="20.32" y1="12.065" x2="20.955" y2="11.43" width="0.127" layer="21"/>
<wire x1="20.955" y1="11.43" x2="20.32" y2="10.795" width="0.127" layer="21"/>
<wire x1="20.32" y1="10.795" x2="20.32" y2="9.525" width="0.127" layer="21"/>
<wire x1="20.32" y1="9.525" x2="20.955" y2="8.89" width="0.127" layer="21"/>
<wire x1="20.955" y1="8.89" x2="20.32" y2="8.255" width="0.127" layer="21"/>
<wire x1="20.32" y1="8.255" x2="20.32" y2="6.985" width="0.127" layer="21"/>
<wire x1="20.32" y1="6.985" x2="20.955" y2="6.35" width="0.127" layer="21"/>
<wire x1="20.955" y1="6.35" x2="20.32" y2="5.715" width="0.127" layer="21"/>
<wire x1="20.32" y1="5.715" x2="20.32" y2="4.445" width="0.127" layer="21"/>
<wire x1="20.32" y1="4.445" x2="20.955" y2="3.81" width="0.127" layer="21"/>
<wire x1="20.955" y1="3.81" x2="22.225" y2="3.81" width="0.127" layer="21"/>
<wire x1="22.86" y1="18.415" x2="22.225" y2="19.05" width="0.127" layer="21"/>
<wire x1="22.86" y1="4.445" x2="23.495" y2="3.81" width="0.127" layer="21"/>
<wire x1="22.225" y1="3.81" x2="22.86" y2="4.445" width="0.127" layer="21"/>
<pad name="PTE21" x="21.59" y="7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE22" x="21.59" y="10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE23" x="21.59" y="12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE29" x="21.59" y="15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE30" x="21.59" y="17.78" drill="0.9" shape="square" rot="R180"/>
<pad name="RESET" x="24.13" y="-12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="P3V3" x="24.13" y="-10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="5V" x="24.13" y="-7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="GND1" x="24.13" y="-5.08" drill="0.9" shape="square" rot="R180"/>
<pad name="GND0" x="24.13" y="-2.54" drill="0.9" shape="square" rot="R180"/>
<pad name="VIN" x="24.13" y="0" drill="0.9" shape="square" rot="R180"/>
<wire x1="23.495" y1="-19.05" x2="24.765" y2="-19.05" width="0.127" layer="21"/>
<wire x1="20.955" y1="-19.05" x2="22.225" y2="-19.05" width="0.127" layer="21"/>
<wire x1="23.495" y1="1.27" x2="24.765" y2="1.27" width="0.127" layer="21"/>
<wire x1="20.955" y1="1.27" x2="22.225" y2="1.27" width="0.127" layer="21"/>
<wire x1="22.225" y1="-19.05" x2="22.86" y2="-18.415" width="0.127" layer="21"/>
<wire x1="22.86" y1="-18.415" x2="23.495" y2="-19.05" width="0.127" layer="21"/>
<wire x1="22.86" y1="0.635" x2="22.225" y2="1.27" width="0.127" layer="21"/>
<wire x1="23.495" y1="1.27" x2="22.86" y2="0.635" width="0.127" layer="21"/>
<pad name="3V3" x="24.13" y="-15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="PTB9" x="21.59" y="-15.24" drill="0.9" shape="square" rot="R180"/>
<pad name="PTB10" x="21.59" y="-12.7" drill="0.9" shape="square" rot="R180"/>
<pad name="PTB11" x="21.59" y="-10.16" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE2" x="21.59" y="-7.62" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE3" x="21.59" y="-5.08" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE4" x="21.59" y="-2.54" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE5" x="21.59" y="0" drill="0.9" shape="square" rot="R180"/>
<pad name="NC1" x="24.13" y="-17.78" drill="0.9" shape="square" rot="R180"/>
<pad name="PTB8" x="21.59" y="-17.78" drill="0.9" shape="square" rot="R180"/>
<wire x1="25.4" y1="-17.145" x2="24.765" y2="-16.51" width="0.127" layer="21"/>
<wire x1="24.765" y1="-16.51" x2="25.4" y2="-15.875" width="0.127" layer="21"/>
<wire x1="25.4" y1="-18.415" x2="25.4" y2="-17.145" width="0.127" layer="21"/>
<wire x1="20.32" y1="-18.415" x2="20.32" y2="-17.145" width="0.127" layer="21"/>
<wire x1="25.4" y1="-15.875" x2="25.4" y2="-14.605" width="0.127" layer="21"/>
<wire x1="20.32" y1="-14.605" x2="20.32" y2="-15.875" width="0.127" layer="21"/>
<wire x1="20.955" y1="-16.51" x2="20.32" y2="-17.145" width="0.127" layer="21"/>
<wire x1="24.765" y1="-13.97" x2="25.4" y2="-13.335" width="0.127" layer="21"/>
<wire x1="20.32" y1="-12.065" x2="20.32" y2="-13.335" width="0.127" layer="21"/>
<wire x1="20.32" y1="-13.335" x2="20.955" y2="-13.97" width="0.127" layer="21"/>
<wire x1="20.955" y1="-13.97" x2="20.32" y2="-14.605" width="0.127" layer="21"/>
<wire x1="20.32" y1="-15.875" x2="20.955" y2="-16.51" width="0.127" layer="21"/>
<wire x1="25.4" y1="-14.605" x2="24.765" y2="-13.97" width="0.127" layer="21"/>
<wire x1="25.4" y1="-12.065" x2="25.4" y2="-13.335" width="0.127" layer="21"/>
<text x="25.654" y="-14.351" size="0.6096" layer="21" rot="R270">3V3</text>
<text x="25.654" y="-17.145" size="0.6096" layer="21" rot="R270">NC</text>
<text x="20.066" y="-17.145" size="0.6096" layer="21" rot="R90" align="bottom-right">B8</text>
<text x="20.066" y="-14.605" size="0.6096" layer="21" rot="R90" align="bottom-right">B9</text>
<text x="20.066" y="-11.811" size="0.6096" layer="21" rot="R90" align="bottom-right">B10</text>
<text x="20.066" y="-9.271" size="0.6096" layer="21" rot="R90" align="bottom-right">B11</text>
<text x="20.066" y="-6.985" size="0.6096" layer="21" rot="R90" align="bottom-right">E2</text>
<wire x1="20.32" y1="-6.985" x2="20.32" y2="-8.255" width="0.127" layer="21"/>
<text x="20.066" y="-4.445" size="0.6096" layer="21" rot="R90" align="bottom-right">E3</text>
<text x="20.066" y="-1.905" size="0.6096" layer="21" rot="R90" align="bottom-right">E4</text>
<text x="20.066" y="0.635" size="0.6096" layer="21" rot="R90" align="bottom-right">E5</text>
<text x="20.066" y="5.969" size="0.6096" layer="21" rot="R90" align="bottom-right">E20</text>
<text x="20.066" y="8.509" size="0.6096" layer="21" rot="R90" align="bottom-right">E21</text>
<text x="20.066" y="11.049" size="0.6096" layer="21" rot="R90" align="bottom-right">E22</text>
<text x="20.066" y="13.589" size="0.6096" layer="21" rot="R90" align="bottom-right">E23</text>
<text x="20.066" y="18.669" size="0.6096" layer="21" rot="R90" align="bottom-right">E30</text>
<text x="20.066" y="16.129" size="0.6096" layer="21" rot="R90" align="bottom-right">E29</text>
<wire x1="-22.225" y1="-2.54" x2="-20.955" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-2.54" x2="-23.495" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-22.86" y1="-27.305" x2="-22.225" y2="-27.94" width="0.127" layer="21"/>
<wire x1="-22.225" y1="-27.94" x2="-20.955" y2="-27.94" width="0.127" layer="21"/>
<wire x1="-23.495" y1="-27.94" x2="-22.86" y2="-27.305" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-27.94" x2="-23.495" y2="-27.94" width="0.127" layer="21"/>
<wire x1="-22.225" y1="-2.54" x2="-22.86" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-22.86" y1="-3.175" x2="-23.495" y2="-2.54" width="0.127" layer="21"/>
<pad name="PTC12" x="-21.59" y="-3.81" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC13" x="-21.59" y="-6.35" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC16" x="-21.59" y="-8.89" drill="0.9" shape="square" rot="R180"/>
<pad name="PTC17" x="-21.59" y="-11.43" drill="0.9" shape="square" rot="R180"/>
<pad name="PTA16" x="-21.59" y="-13.97" drill="0.9" shape="square" rot="R180"/>
<pad name="PTA17" x="-21.59" y="-16.51" drill="0.9" shape="square" rot="R180"/>
<pad name="PTE31" x="-21.59" y="-19.05" drill="0.9" shape="square" rot="R180"/>
<pad name="PTD7" x="-21.59" y="-26.67" drill="0.9" shape="square" rot="R180"/>
<pad name="D15" x="-24.13" y="-26.67" drill="0.9" shape="square" rot="R180"/>
<pad name="GND2" x="-24.13" y="-19.05" drill="0.9" shape="square" rot="R180"/>
<pad name="D13" x="-24.13" y="-16.51" drill="0.9" shape="square" rot="R180"/>
<pad name="D12" x="-24.13" y="-13.97" drill="0.9" shape="square" rot="R180"/>
<pad name="D11" x="-24.13" y="-11.43" drill="0.9" shape="square" rot="R180"/>
<pad name="D10" x="-24.13" y="-8.89" drill="0.9" shape="square" rot="R180"/>
<pad name="D9" x="-24.13" y="-6.35" drill="0.9" shape="square" rot="R180"/>
<pad name="D8" x="-24.13" y="-3.81" drill="0.9" shape="square" rot="R180"/>
<pad name="NC2" x="-21.59" y="-21.59" drill="0.9" shape="square" rot="R180"/>
<pad name="PTD6" x="-21.59" y="-24.13" drill="0.9" shape="square" rot="R180"/>
<pad name="D14" x="-24.13" y="-24.13" drill="0.9" shape="square" rot="R180"/>
<pad name="AREF" x="-24.13" y="-21.59" drill="0.9" shape="square" rot="R180"/>
<wire x1="-24.765" y1="-22.86" x2="-25.4" y2="-23.495" width="0.127" layer="21"/>
<wire x1="-24.765" y1="-25.4" x2="-25.4" y2="-26.035" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-26.035" x2="-20.955" y2="-25.4" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-23.495" x2="-20.955" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-22.225" x2="-20.32" y2="-20.955" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-24.765" x2="-20.32" y2="-23.495" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-27.305" x2="-25.4" y2="-26.035" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-27.305" x2="-20.32" y2="-26.035" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-23.495" x2="-25.4" y2="-24.765" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-20.955" x2="-25.4" y2="-22.225" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-22.86" x2="-20.32" y2="-22.225" width="0.127" layer="21"/>
<wire x1="-20.955" y1="-25.4" x2="-20.32" y2="-24.765" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-24.765" x2="-24.765" y2="-25.4" width="0.127" layer="21"/>
<wire x1="-25.4" y1="-22.225" x2="-24.765" y2="-22.86" width="0.127" layer="21"/>
<text x="-20.193" y="-25.908" size="0.6096" layer="21" rot="R270">D7</text>
<text x="-20.193" y="-23.495" size="0.6096" layer="21" rot="R270">D6</text>
<text x="-20.066" y="-20.955" size="0.6096" layer="21" rot="R270">NC</text>
<text x="-20.066" y="-18.161" size="0.6096" layer="21" rot="R270">E31</text>
<text x="-20.066" y="-15.621" size="0.6096" layer="21" rot="R270">A17</text>
<text x="-20.066" y="-13.081" size="0.6096" layer="21" rot="R270">A16</text>
<text x="-20.066" y="-10.541" size="0.6096" layer="21" rot="R270">C17</text>
<text x="-20.066" y="-8.001" size="0.6096" layer="21" rot="R270">C16</text>
<text x="-20.066" y="-5.461" size="0.6096" layer="21" rot="R270">C13</text>
<text x="-20.066" y="-2.921" size="0.6096" layer="21" rot="R270">C12</text>
<text x="-25.654" y="-20.447" size="0.6096" layer="21" rot="R90" align="bottom-right">AREF</text>
<text x="-25.654" y="-23.241" size="0.6096" layer="21" rot="R90" align="bottom-right">D14</text>
<text x="-25.654" y="-25.781" size="0.6096" layer="21" rot="R90" align="bottom-right">D15</text>
<text x="-22.86" y="19.685" size="0.6096" layer="21" align="bottom-center">&gt;NAME</text>
<wire x1="-26.4" y1="28.8" x2="-26.4" y2="-37.2" width="0.127" layer="51"/>
<wire x1="26.4" y1="29.2" x2="26.4" y2="-37" width="0.127" layer="51"/>
<wire x1="18.2" y1="-45.4" x2="14" y2="-45.4" width="0.127" layer="51"/>
<wire x1="14" y1="-45.4" x2="6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="6" y1="-45.4" x2="-6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-6" y1="-45.4" x2="-14" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-14" y1="-45.4" x2="-18" y2="-45.4" width="0.127" layer="51"/>
<wire x1="18" y1="37.2" x2="-18.2" y2="37.2" width="0.127" layer="51"/>
<wire x1="14" y1="-45.4" x2="14" y2="-47" width="0.127" layer="51"/>
<wire x1="14" y1="-47" x2="6" y2="-47" width="0.127" layer="51"/>
<wire x1="6" y1="-47" x2="6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-14" y1="-45.4" x2="-14" y2="-47" width="0.127" layer="51"/>
<wire x1="-14" y1="-47" x2="-6" y2="-47" width="0.127" layer="51"/>
<wire x1="-6" y1="-47" x2="-6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="18" y1="37.2" x2="26.4" y2="29" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="-26.4" y1="28.8" x2="-18.2" y2="37.2" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="-18" y1="-45.4" x2="-26.4" y2="-37.2" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="26.4" y1="-37" x2="18.2" y2="-45.4" width="0.127" layer="51" curve="-91.397181"/>
</package>
<package name="FRDM_KL25Z_REVERT">
<wire x1="-24.765" y1="19.05" x2="-23.495" y2="19.05" width="0.127" layer="22"/>
<wire x1="-24.765" y1="19.05" x2="-25.4" y2="18.415" width="0.127" layer="22"/>
<wire x1="-23.495" y1="19.05" x2="-22.86" y2="18.415" width="0.127" layer="22"/>
<wire x1="-25.4" y1="18.415" x2="-25.4" y2="17.145" width="0.127" layer="22"/>
<wire x1="-25.4" y1="17.145" x2="-24.765" y2="16.51" width="0.127" layer="22"/>
<wire x1="-24.765" y1="16.51" x2="-25.4" y2="15.875" width="0.127" layer="22"/>
<wire x1="-25.4" y1="15.875" x2="-25.4" y2="14.605" width="0.127" layer="22"/>
<wire x1="-25.4" y1="14.605" x2="-24.765" y2="13.97" width="0.127" layer="22"/>
<wire x1="-24.765" y1="13.97" x2="-25.4" y2="13.335" width="0.127" layer="22"/>
<wire x1="-25.4" y1="13.335" x2="-25.4" y2="12.065" width="0.127" layer="22"/>
<wire x1="-25.4" y1="12.065" x2="-24.765" y2="11.43" width="0.127" layer="22"/>
<wire x1="-24.765" y1="11.43" x2="-25.4" y2="10.795" width="0.127" layer="22"/>
<wire x1="-25.4" y1="10.795" x2="-25.4" y2="9.525" width="0.127" layer="22"/>
<wire x1="-25.4" y1="9.525" x2="-24.765" y2="8.89" width="0.127" layer="22"/>
<wire x1="-24.765" y1="8.89" x2="-25.4" y2="8.255" width="0.127" layer="22"/>
<wire x1="-25.4" y1="8.255" x2="-25.4" y2="6.985" width="0.127" layer="22"/>
<wire x1="-25.4" y1="6.985" x2="-24.765" y2="6.35" width="0.127" layer="22"/>
<wire x1="-24.765" y1="6.35" x2="-25.4" y2="5.715" width="0.127" layer="22"/>
<wire x1="-25.4" y1="5.715" x2="-25.4" y2="4.445" width="0.127" layer="22"/>
<wire x1="-25.4" y1="4.445" x2="-24.765" y2="3.81" width="0.127" layer="22"/>
<wire x1="-24.765" y1="3.81" x2="-23.495" y2="3.81" width="0.127" layer="22"/>
<wire x1="-20.955" y1="1.27" x2="-20.32" y2="0.635" width="0.127" layer="22"/>
<wire x1="-20.32" y1="0.635" x2="-20.32" y2="-0.635" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-0.635" x2="-20.955" y2="-1.27" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-1.27" x2="-20.32" y2="-1.905" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-1.905" x2="-20.32" y2="-3.175" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-3.175" x2="-20.955" y2="-3.81" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-3.81" x2="-20.32" y2="-4.445" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-4.445" x2="-20.32" y2="-5.715" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-5.715" x2="-20.955" y2="-6.35" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-6.35" x2="-20.32" y2="-6.985" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-8.255" x2="-20.955" y2="-8.89" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-8.89" x2="-20.32" y2="-9.525" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-9.525" x2="-20.32" y2="-10.795" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-10.795" x2="-20.955" y2="-11.43" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-11.43" x2="-20.32" y2="-12.065" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-18.415" x2="-20.955" y2="-19.05" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-19.05" x2="-25.4" y2="-18.415" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-12.065" x2="-24.765" y2="-11.43" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-11.43" x2="-25.4" y2="-10.795" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-10.795" x2="-25.4" y2="-9.525" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-9.525" x2="-24.765" y2="-8.89" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-8.89" x2="-25.4" y2="-8.255" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-8.255" x2="-25.4" y2="-6.985" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-6.985" x2="-24.765" y2="-6.35" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-6.35" x2="-25.4" y2="-5.715" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-5.715" x2="-25.4" y2="-4.445" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-4.445" x2="-24.765" y2="-3.81" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-3.81" x2="-25.4" y2="-3.175" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-3.175" x2="-25.4" y2="-1.905" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-1.905" x2="-24.765" y2="-1.27" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-1.27" x2="-25.4" y2="-0.635" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-0.635" x2="-25.4" y2="0.635" width="0.127" layer="22"/>
<wire x1="-25.4" y1="0.635" x2="-24.765" y2="1.27" width="0.127" layer="22"/>
<wire x1="23.495" y1="19.05" x2="24.765" y2="19.05" width="0.127" layer="22"/>
<wire x1="24.765" y1="19.05" x2="25.4" y2="18.415" width="0.127" layer="22"/>
<wire x1="25.4" y1="18.415" x2="25.4" y2="17.145" width="0.127" layer="22"/>
<wire x1="25.4" y1="17.145" x2="24.765" y2="16.51" width="0.127" layer="22"/>
<wire x1="24.765" y1="16.51" x2="25.4" y2="15.875" width="0.127" layer="22"/>
<wire x1="25.4" y1="15.875" x2="25.4" y2="14.605" width="0.127" layer="22"/>
<wire x1="25.4" y1="14.605" x2="24.765" y2="13.97" width="0.127" layer="22"/>
<wire x1="24.765" y1="13.97" x2="25.4" y2="13.335" width="0.127" layer="22"/>
<wire x1="25.4" y1="13.335" x2="25.4" y2="12.065" width="0.127" layer="22"/>
<wire x1="25.4" y1="12.065" x2="24.765" y2="11.43" width="0.127" layer="22"/>
<wire x1="24.765" y1="11.43" x2="25.4" y2="10.795" width="0.127" layer="22"/>
<wire x1="25.4" y1="10.795" x2="25.4" y2="9.525" width="0.127" layer="22"/>
<wire x1="25.4" y1="9.525" x2="24.765" y2="8.89" width="0.127" layer="22"/>
<wire x1="24.765" y1="8.89" x2="25.4" y2="8.255" width="0.127" layer="22"/>
<wire x1="25.4" y1="8.255" x2="25.4" y2="6.985" width="0.127" layer="22"/>
<wire x1="25.4" y1="6.985" x2="24.765" y2="6.35" width="0.127" layer="22"/>
<wire x1="24.765" y1="6.35" x2="25.4" y2="5.715" width="0.127" layer="22"/>
<wire x1="25.4" y1="5.715" x2="25.4" y2="4.445" width="0.127" layer="22"/>
<wire x1="25.4" y1="4.445" x2="24.765" y2="3.81" width="0.127" layer="22"/>
<wire x1="24.765" y1="3.81" x2="25.4" y2="3.175" width="0.127" layer="22"/>
<wire x1="25.4" y1="3.175" x2="25.4" y2="1.905" width="0.127" layer="22"/>
<wire x1="25.4" y1="1.905" x2="24.765" y2="1.27" width="0.127" layer="22"/>
<wire x1="24.765" y1="1.27" x2="25.4" y2="0.635" width="0.127" layer="22"/>
<wire x1="25.4" y1="-0.635" x2="24.765" y2="-1.27" width="0.127" layer="22"/>
<wire x1="24.765" y1="-1.27" x2="23.495" y2="-1.27" width="0.127" layer="22"/>
<wire x1="23.495" y1="-1.27" x2="22.86" y2="-0.635" width="0.127" layer="22"/>
<wire x1="22.86" y1="18.415" x2="23.495" y2="19.05" width="0.127" layer="22"/>
<wire x1="24.765" y1="-2.54" x2="25.4" y2="-3.175" width="0.127" layer="22"/>
<wire x1="25.4" y1="-3.175" x2="25.4" y2="-4.445" width="0.127" layer="22"/>
<wire x1="25.4" y1="-4.445" x2="24.765" y2="-5.08" width="0.127" layer="22"/>
<wire x1="24.765" y1="-5.08" x2="25.4" y2="-5.715" width="0.127" layer="22"/>
<wire x1="25.4" y1="-5.715" x2="25.4" y2="-6.985" width="0.127" layer="22"/>
<wire x1="25.4" y1="-6.985" x2="24.765" y2="-7.62" width="0.127" layer="22"/>
<wire x1="24.765" y1="-7.62" x2="25.4" y2="-8.255" width="0.127" layer="22"/>
<wire x1="25.4" y1="-8.255" x2="25.4" y2="-9.525" width="0.127" layer="22"/>
<wire x1="25.4" y1="-9.525" x2="24.765" y2="-10.16" width="0.127" layer="22"/>
<wire x1="24.765" y1="-10.16" x2="25.4" y2="-10.795" width="0.127" layer="22"/>
<wire x1="25.4" y1="-10.795" x2="25.4" y2="-12.065" width="0.127" layer="22"/>
<wire x1="25.4" y1="-12.065" x2="24.765" y2="-12.7" width="0.127" layer="22"/>
<wire x1="24.765" y1="-12.7" x2="25.4" y2="-13.335" width="0.127" layer="22"/>
<wire x1="25.4" y1="-13.335" x2="25.4" y2="-14.605" width="0.127" layer="22"/>
<wire x1="25.4" y1="-14.605" x2="24.765" y2="-15.24" width="0.127" layer="22"/>
<wire x1="24.765" y1="-15.24" x2="25.4" y2="-15.875" width="0.127" layer="22"/>
<wire x1="25.4" y1="-15.875" x2="25.4" y2="-17.145" width="0.127" layer="22"/>
<wire x1="25.4" y1="-17.145" x2="24.765" y2="-17.78" width="0.127" layer="22"/>
<wire x1="24.765" y1="-17.78" x2="25.4" y2="-18.415" width="0.127" layer="22"/>
<wire x1="25.4" y1="-18.415" x2="25.4" y2="-19.685" width="0.127" layer="22"/>
<wire x1="25.4" y1="-19.685" x2="24.765" y2="-20.32" width="0.127" layer="22"/>
<wire x1="24.765" y1="-20.32" x2="25.4" y2="-20.955" width="0.127" layer="22"/>
<wire x1="25.4" y1="-27.305" x2="24.765" y2="-27.94" width="0.127" layer="22"/>
<wire x1="20.955" y1="-27.94" x2="20.32" y2="-27.305" width="0.127" layer="22"/>
<wire x1="20.32" y1="-20.955" x2="20.955" y2="-20.32" width="0.127" layer="22"/>
<wire x1="20.955" y1="-20.32" x2="20.32" y2="-19.685" width="0.127" layer="22"/>
<wire x1="20.32" y1="-19.685" x2="20.32" y2="-18.415" width="0.127" layer="22"/>
<wire x1="20.32" y1="-18.415" x2="20.955" y2="-17.78" width="0.127" layer="22"/>
<wire x1="20.955" y1="-17.78" x2="20.32" y2="-17.145" width="0.127" layer="22"/>
<wire x1="20.32" y1="-17.145" x2="20.32" y2="-15.875" width="0.127" layer="22"/>
<wire x1="20.32" y1="-15.875" x2="20.955" y2="-15.24" width="0.127" layer="22"/>
<wire x1="20.955" y1="-15.24" x2="20.32" y2="-14.605" width="0.127" layer="22"/>
<wire x1="20.32" y1="-14.605" x2="20.32" y2="-13.335" width="0.127" layer="22"/>
<wire x1="20.32" y1="-13.335" x2="20.955" y2="-12.7" width="0.127" layer="22"/>
<wire x1="20.955" y1="-12.7" x2="20.32" y2="-12.065" width="0.127" layer="22"/>
<wire x1="20.32" y1="-12.065" x2="20.32" y2="-10.795" width="0.127" layer="22"/>
<wire x1="20.32" y1="-10.795" x2="20.955" y2="-10.16" width="0.127" layer="22"/>
<wire x1="20.955" y1="-10.16" x2="20.32" y2="-9.525" width="0.127" layer="22"/>
<wire x1="20.32" y1="-9.525" x2="20.32" y2="-8.255" width="0.127" layer="22"/>
<wire x1="20.32" y1="-8.255" x2="20.955" y2="-7.62" width="0.127" layer="22"/>
<wire x1="20.955" y1="-7.62" x2="20.32" y2="-6.985" width="0.127" layer="22"/>
<wire x1="20.32" y1="-6.985" x2="20.32" y2="-5.715" width="0.127" layer="22"/>
<wire x1="20.32" y1="-5.715" x2="20.955" y2="-5.08" width="0.127" layer="22"/>
<wire x1="20.955" y1="-5.08" x2="20.32" y2="-4.445" width="0.127" layer="22"/>
<wire x1="20.32" y1="-4.445" x2="20.32" y2="-3.175" width="0.127" layer="22"/>
<wire x1="20.32" y1="-3.175" x2="20.955" y2="-2.54" width="0.127" layer="22"/>
<text x="-26.289" y="-4.191" size="0.6096" layer="21" rot="R270">GND</text>
<text x="-26.289" y="-1.651" size="0.6096" layer="21" rot="R270">GND</text>
<text x="-26.289" y="0.889" size="0.6096" layer="21" rot="R270">VIN</text>
<text x="-26.289" y="-6.985" size="0.6096" layer="21" rot="R270">5V</text>
<text x="-26.289" y="-9.271" size="0.6096" layer="21" rot="R270">3V3</text>
<text x="-26.289" y="-11.811" size="0.6096" layer="21" rot="R270">RES</text>
<text x="-26.289" y="5.715" size="0.6096" layer="21" rot="R270">A0</text>
<text x="-26.289" y="8.255" size="0.6096" layer="21" rot="R270">A1</text>
<text x="-26.289" y="10.795" size="0.6096" layer="21" rot="R270">A2</text>
<text x="-26.289" y="13.335" size="0.6096" layer="21" rot="R270">A3</text>
<text x="-26.289" y="15.875" size="0.6096" layer="21" rot="R270">A4</text>
<text x="-26.289" y="18.415" size="0.6096" layer="21" rot="R270">A5</text>
<text x="26.289" y="18.415" size="0.6096" layer="21" rot="R90" align="bottom-right">D0</text>
<text x="26.289" y="15.875" size="0.6096" layer="21" rot="R90" align="bottom-right">D1</text>
<text x="26.289" y="13.335" size="0.6096" layer="21" rot="R90" align="bottom-right">D2</text>
<text x="26.289" y="10.795" size="0.6096" layer="21" rot="R90" align="bottom-right">D3</text>
<text x="26.289" y="8.255" size="0.6096" layer="21" rot="R90" align="bottom-right">D4</text>
<text x="26.289" y="5.715" size="0.6096" layer="21" rot="R90" align="bottom-right">D5</text>
<text x="26.289" y="3.175" size="0.6096" layer="21" rot="R90" align="bottom-right">D6</text>
<text x="26.289" y="0.635" size="0.6096" layer="21" rot="R90" align="bottom-right">D7</text>
<text x="26.289" y="-3.175" size="0.6096" layer="21" rot="R90" align="bottom-right">D8</text>
<text x="26.289" y="-5.715" size="0.6096" layer="21" rot="R90" align="bottom-right">D9</text>
<text x="26.289" y="-8.001" size="0.6096" layer="21" rot="R90" align="bottom-right">D10</text>
<text x="26.289" y="-10.541" size="0.6096" layer="21" rot="R90" align="bottom-right">D11</text>
<text x="26.289" y="-13.081" size="0.6096" layer="21" rot="R90" align="bottom-right">D12</text>
<text x="26.289" y="-15.621" size="0.6096" layer="21" rot="R90" align="bottom-right">D13</text>
<text x="-22.86" y="19.685" size="0.6096" layer="21" align="bottom-center">&gt;NAME</text>
<text x="26.289" y="-18.161" size="0.6096" layer="21" rot="R90" align="bottom-right">GND</text>
<wire x1="20.955" y1="19.05" x2="22.225" y2="19.05" width="0.127" layer="22"/>
<wire x1="22.225" y1="19.05" x2="22.86" y2="18.415" width="0.127" layer="22"/>
<wire x1="25.4" y1="0.635" x2="25.4" y2="-0.635" width="0.127" layer="22"/>
<wire x1="22.86" y1="-0.635" x2="22.225" y2="-1.27" width="0.127" layer="22"/>
<wire x1="22.225" y1="-1.27" x2="20.955" y2="-1.27" width="0.127" layer="22"/>
<wire x1="20.955" y1="-1.27" x2="20.32" y2="-0.635" width="0.127" layer="22"/>
<wire x1="20.32" y1="-0.635" x2="20.32" y2="0.635" width="0.127" layer="22"/>
<wire x1="20.32" y1="0.635" x2="20.955" y2="1.27" width="0.127" layer="22"/>
<wire x1="20.955" y1="1.27" x2="20.32" y2="1.905" width="0.127" layer="22"/>
<wire x1="20.32" y1="1.905" x2="20.32" y2="3.175" width="0.127" layer="22"/>
<wire x1="20.32" y1="3.175" x2="20.955" y2="3.81" width="0.127" layer="22"/>
<wire x1="20.955" y1="3.81" x2="20.32" y2="4.445" width="0.127" layer="22"/>
<wire x1="20.32" y1="4.445" x2="20.32" y2="5.715" width="0.127" layer="22"/>
<wire x1="20.32" y1="5.715" x2="20.955" y2="6.35" width="0.127" layer="22"/>
<wire x1="20.955" y1="6.35" x2="20.32" y2="6.985" width="0.127" layer="22"/>
<wire x1="20.32" y1="6.985" x2="20.32" y2="8.255" width="0.127" layer="22"/>
<wire x1="20.32" y1="8.255" x2="20.955" y2="8.89" width="0.127" layer="22"/>
<wire x1="20.955" y1="8.89" x2="20.32" y2="9.525" width="0.127" layer="22"/>
<wire x1="20.32" y1="9.525" x2="20.32" y2="10.795" width="0.127" layer="22"/>
<wire x1="20.32" y1="10.795" x2="20.955" y2="11.43" width="0.127" layer="22"/>
<wire x1="20.955" y1="11.43" x2="20.32" y2="12.065" width="0.127" layer="22"/>
<wire x1="20.32" y1="12.065" x2="20.32" y2="13.335" width="0.127" layer="22"/>
<wire x1="20.32" y1="13.335" x2="20.955" y2="13.97" width="0.127" layer="22"/>
<wire x1="20.955" y1="13.97" x2="20.32" y2="14.605" width="0.127" layer="22"/>
<wire x1="20.32" y1="14.605" x2="20.32" y2="15.875" width="0.127" layer="22"/>
<wire x1="20.32" y1="15.875" x2="20.955" y2="16.51" width="0.127" layer="22"/>
<wire x1="20.955" y1="16.51" x2="20.32" y2="17.145" width="0.127" layer="22"/>
<wire x1="20.32" y1="17.145" x2="20.32" y2="18.415" width="0.127" layer="22"/>
<wire x1="20.32" y1="18.415" x2="20.955" y2="19.05" width="0.127" layer="22"/>
<text x="19.431" y="18.415" size="0.6096" layer="21" rot="R270">C7</text>
<text x="19.431" y="15.875" size="0.6096" layer="21" rot="R270">C0</text>
<text x="19.431" y="13.335" size="0.6096" layer="21" rot="R270">C3</text>
<text x="19.431" y="10.795" size="0.6096" layer="21" rot="R270">C4</text>
<text x="19.431" y="8.255" size="0.6096" layer="21" rot="R270">C5</text>
<text x="19.431" y="5.715" size="0.6096" layer="21" rot="R270">C6</text>
<text x="19.431" y="3.429" size="0.6096" layer="21" rot="R270">C10</text>
<text x="19.431" y="0.889" size="0.6096" layer="21" rot="R270">C11</text>
<pad name="PTC11" x="21.59" y="0" drill="0.9" shape="square"/>
<pad name="PTC10" x="21.59" y="2.54" drill="0.9" shape="square"/>
<pad name="PTC6" x="21.59" y="5.08" drill="0.9" shape="square"/>
<pad name="PTC5" x="21.59" y="7.62" drill="0.9" shape="square"/>
<pad name="PTC4" x="21.59" y="10.16" drill="0.9" shape="square"/>
<pad name="PTC3" x="21.59" y="12.7" drill="0.9" shape="square"/>
<pad name="PTC0" x="21.59" y="15.24" drill="0.9" shape="square"/>
<pad name="PTC7" x="21.59" y="17.78" drill="0.9" shape="square"/>
<pad name="A0" x="-24.13" y="5.08" drill="0.9" shape="square"/>
<pad name="A1" x="-24.13" y="7.62" drill="0.9" shape="square"/>
<pad name="A2" x="-24.13" y="10.16" drill="0.9" shape="square"/>
<pad name="A3" x="-24.13" y="12.7" drill="0.9" shape="square"/>
<pad name="A4" x="-24.13" y="15.24" drill="0.9" shape="square"/>
<pad name="A5" x="-24.13" y="17.78" drill="0.9" shape="square"/>
<pad name="D7" x="24.13" y="0" drill="0.9" shape="square"/>
<pad name="D6" x="24.13" y="2.54" drill="0.9" shape="square"/>
<pad name="D5" x="24.13" y="5.08" drill="0.9" shape="square"/>
<pad name="D4" x="24.13" y="7.62" drill="0.9" shape="square"/>
<pad name="D3" x="24.13" y="10.16" drill="0.9" shape="square"/>
<pad name="D2" x="24.13" y="12.7" drill="0.9" shape="square"/>
<pad name="D1" x="24.13" y="15.24" drill="0.9" shape="square"/>
<pad name="D0" x="24.13" y="17.78" drill="0.9" shape="square"/>
<pad name="PTE20" x="-21.59" y="5.08" drill="0.9" shape="square"/>
<wire x1="-22.225" y1="19.05" x2="-20.955" y2="19.05" width="0.127" layer="22"/>
<wire x1="-20.955" y1="19.05" x2="-20.32" y2="18.415" width="0.127" layer="22"/>
<wire x1="-20.32" y1="18.415" x2="-20.32" y2="17.145" width="0.127" layer="22"/>
<wire x1="-20.32" y1="17.145" x2="-20.955" y2="16.51" width="0.127" layer="22"/>
<wire x1="-20.955" y1="16.51" x2="-20.32" y2="15.875" width="0.127" layer="22"/>
<wire x1="-20.32" y1="15.875" x2="-20.32" y2="14.605" width="0.127" layer="22"/>
<wire x1="-20.32" y1="14.605" x2="-20.955" y2="13.97" width="0.127" layer="22"/>
<wire x1="-20.955" y1="13.97" x2="-20.32" y2="13.335" width="0.127" layer="22"/>
<wire x1="-20.32" y1="13.335" x2="-20.32" y2="12.065" width="0.127" layer="22"/>
<wire x1="-20.32" y1="12.065" x2="-20.955" y2="11.43" width="0.127" layer="22"/>
<wire x1="-20.955" y1="11.43" x2="-20.32" y2="10.795" width="0.127" layer="22"/>
<wire x1="-20.32" y1="10.795" x2="-20.32" y2="9.525" width="0.127" layer="22"/>
<wire x1="-20.32" y1="9.525" x2="-20.955" y2="8.89" width="0.127" layer="22"/>
<wire x1="-20.955" y1="8.89" x2="-20.32" y2="8.255" width="0.127" layer="22"/>
<wire x1="-20.32" y1="8.255" x2="-20.32" y2="6.985" width="0.127" layer="22"/>
<wire x1="-20.32" y1="6.985" x2="-20.955" y2="6.35" width="0.127" layer="22"/>
<wire x1="-20.955" y1="6.35" x2="-20.32" y2="5.715" width="0.127" layer="22"/>
<wire x1="-20.32" y1="5.715" x2="-20.32" y2="4.445" width="0.127" layer="22"/>
<wire x1="-20.32" y1="4.445" x2="-20.955" y2="3.81" width="0.127" layer="22"/>
<wire x1="-20.955" y1="3.81" x2="-22.225" y2="3.81" width="0.127" layer="22"/>
<wire x1="-22.86" y1="18.415" x2="-22.225" y2="19.05" width="0.127" layer="22"/>
<wire x1="-22.86" y1="4.445" x2="-23.495" y2="3.81" width="0.127" layer="22"/>
<wire x1="-22.225" y1="3.81" x2="-22.86" y2="4.445" width="0.127" layer="22"/>
<pad name="PTE21" x="-21.59" y="7.62" drill="0.9" shape="square"/>
<pad name="PTE22" x="-21.59" y="10.16" drill="0.9" shape="square"/>
<pad name="PTE23" x="-21.59" y="12.7" drill="0.9" shape="square"/>
<pad name="PTE29" x="-21.59" y="15.24" drill="0.9" shape="square"/>
<pad name="PTE30" x="-21.59" y="17.78" drill="0.9" shape="square"/>
<pad name="RESET" x="-24.13" y="-12.7" drill="0.9" shape="square"/>
<pad name="P3V3" x="-24.13" y="-10.16" drill="0.9" shape="square"/>
<pad name="5V" x="-24.13" y="-7.62" drill="0.9" shape="square"/>
<pad name="GND1" x="-24.13" y="-5.08" drill="0.9" shape="square"/>
<pad name="GND0" x="-24.13" y="-2.54" drill="0.9" shape="square"/>
<pad name="VIN" x="-24.13" y="0" drill="0.9" shape="square"/>
<wire x1="-23.495" y1="-19.05" x2="-24.765" y2="-19.05" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-19.05" x2="-22.225" y2="-19.05" width="0.127" layer="22"/>
<wire x1="-23.495" y1="1.27" x2="-24.765" y2="1.27" width="0.127" layer="22"/>
<wire x1="-20.955" y1="1.27" x2="-22.225" y2="1.27" width="0.127" layer="22"/>
<wire x1="-22.225" y1="-19.05" x2="-22.86" y2="-18.415" width="0.127" layer="22"/>
<wire x1="-22.86" y1="-18.415" x2="-23.495" y2="-19.05" width="0.127" layer="22"/>
<wire x1="-22.86" y1="0.635" x2="-22.225" y2="1.27" width="0.127" layer="22"/>
<wire x1="-23.495" y1="1.27" x2="-22.86" y2="0.635" width="0.127" layer="22"/>
<pad name="3V3" x="-24.13" y="-15.24" drill="0.9" shape="square"/>
<pad name="PTB9" x="-21.59" y="-15.24" drill="0.9" shape="square"/>
<pad name="PTB10" x="-21.59" y="-12.7" drill="0.9" shape="square"/>
<pad name="PTB11" x="-21.59" y="-10.16" drill="0.9" shape="square"/>
<pad name="PTE2" x="-21.59" y="-7.62" drill="0.9" shape="square"/>
<pad name="PTE3" x="-21.59" y="-5.08" drill="0.9" shape="square"/>
<pad name="PTE4" x="-21.59" y="-2.54" drill="0.9" shape="square"/>
<pad name="PTE5" x="-21.59" y="0" drill="0.9" shape="square"/>
<pad name="NC1" x="-24.13" y="-17.78" drill="0.9" shape="square"/>
<pad name="PTB8" x="-21.59" y="-17.78" drill="0.9" shape="square"/>
<wire x1="-25.4" y1="-17.145" x2="-24.765" y2="-16.51" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-16.51" x2="-25.4" y2="-15.875" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-18.415" x2="-25.4" y2="-17.145" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-18.415" x2="-20.32" y2="-17.145" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-15.875" x2="-25.4" y2="-14.605" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-14.605" x2="-20.32" y2="-15.875" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-16.51" x2="-20.32" y2="-17.145" width="0.127" layer="22"/>
<wire x1="-24.765" y1="-13.97" x2="-25.4" y2="-13.335" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-12.065" x2="-20.32" y2="-13.335" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-13.335" x2="-20.955" y2="-13.97" width="0.127" layer="22"/>
<wire x1="-20.955" y1="-13.97" x2="-20.32" y2="-14.605" width="0.127" layer="22"/>
<wire x1="-20.32" y1="-15.875" x2="-20.955" y2="-16.51" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-14.605" x2="-24.765" y2="-13.97" width="0.127" layer="22"/>
<wire x1="-25.4" y1="-12.065" x2="-25.4" y2="-13.335" width="0.127" layer="22"/>
<text x="-26.289" y="-14.351" size="0.6096" layer="21" rot="R270">3V3</text>
<text x="-26.289" y="-17.145" size="0.6096" layer="21" rot="R270">NC</text>
<text x="-19.431" y="-17.145" size="0.6096" layer="21" rot="R90" align="bottom-right">B8</text>
<text x="-19.431" y="-14.605" size="0.6096" layer="21" rot="R90" align="bottom-right">B9</text>
<text x="-19.431" y="-11.811" size="0.6096" layer="21" rot="R90" align="bottom-right">B10</text>
<text x="-19.431" y="-9.271" size="0.6096" layer="21" rot="R90" align="bottom-right">B11</text>
<text x="-19.431" y="-6.985" size="0.6096" layer="21" rot="R90" align="bottom-right">E2</text>
<wire x1="-20.32" y1="-6.985" x2="-20.32" y2="-8.255" width="0.127" layer="22"/>
<text x="-19.431" y="-4.445" size="0.6096" layer="21" rot="R90" align="bottom-right">E3</text>
<text x="-19.431" y="-1.905" size="0.6096" layer="21" rot="R90" align="bottom-right">E4</text>
<text x="-19.431" y="0.635" size="0.6096" layer="21" rot="R90" align="bottom-right">E5</text>
<text x="-19.431" y="5.969" size="0.6096" layer="21" rot="R90" align="bottom-right">E20</text>
<text x="-19.431" y="8.509" size="0.6096" layer="21" rot="R90" align="bottom-right">E21</text>
<text x="-19.431" y="11.049" size="0.6096" layer="21" rot="R90" align="bottom-right">E22</text>
<text x="-19.431" y="13.589" size="0.6096" layer="21" rot="R90" align="bottom-right">E23</text>
<text x="-19.431" y="18.669" size="0.6096" layer="21" rot="R90" align="bottom-right">E30</text>
<text x="-19.431" y="16.129" size="0.6096" layer="21" rot="R90" align="bottom-right">E29</text>
<wire x1="22.225" y1="-2.54" x2="20.955" y2="-2.54" width="0.127" layer="22"/>
<wire x1="24.765" y1="-2.54" x2="23.495" y2="-2.54" width="0.127" layer="22"/>
<wire x1="22.86" y1="-27.305" x2="22.225" y2="-27.94" width="0.127" layer="22"/>
<wire x1="22.225" y1="-27.94" x2="20.955" y2="-27.94" width="0.127" layer="22"/>
<wire x1="23.495" y1="-27.94" x2="22.86" y2="-27.305" width="0.127" layer="22"/>
<wire x1="24.765" y1="-27.94" x2="23.495" y2="-27.94" width="0.127" layer="22"/>
<wire x1="22.225" y1="-2.54" x2="22.86" y2="-3.175" width="0.127" layer="22"/>
<wire x1="22.86" y1="-3.175" x2="23.495" y2="-2.54" width="0.127" layer="22"/>
<pad name="PTC12" x="21.59" y="-3.81" drill="0.9" shape="square"/>
<pad name="PTC13" x="21.59" y="-6.35" drill="0.9" shape="square"/>
<pad name="PTC16" x="21.59" y="-8.89" drill="0.9" shape="square"/>
<pad name="PTC17" x="21.59" y="-11.43" drill="0.9" shape="square"/>
<pad name="PTA16" x="21.59" y="-13.97" drill="0.9" shape="square"/>
<pad name="PTA17" x="21.59" y="-16.51" drill="0.9" shape="square"/>
<pad name="PTE31" x="21.59" y="-19.05" drill="0.9" shape="square"/>
<pad name="PTD7" x="21.59" y="-26.67" drill="0.9" shape="square"/>
<pad name="D15" x="24.13" y="-26.67" drill="0.9" shape="square"/>
<pad name="GND2" x="24.13" y="-19.05" drill="0.9" shape="square"/>
<pad name="D13" x="24.13" y="-16.51" drill="0.9" shape="square"/>
<pad name="D12" x="24.13" y="-13.97" drill="0.9" shape="square"/>
<pad name="D11" x="24.13" y="-11.43" drill="0.9" shape="square"/>
<pad name="D10" x="24.13" y="-8.89" drill="0.9" shape="square"/>
<pad name="D9" x="24.13" y="-6.35" drill="0.9" shape="square"/>
<pad name="D8" x="24.13" y="-3.81" drill="0.9" shape="square"/>
<pad name="NC2" x="21.59" y="-21.59" drill="0.9" shape="square"/>
<pad name="PTD6" x="21.59" y="-24.13" drill="0.9" shape="square"/>
<pad name="D14" x="24.13" y="-24.13" drill="0.9" shape="square"/>
<pad name="AREF" x="24.13" y="-21.59" drill="0.9" shape="square"/>
<wire x1="24.765" y1="-22.86" x2="25.4" y2="-23.495" width="0.127" layer="22"/>
<wire x1="24.765" y1="-25.4" x2="25.4" y2="-26.035" width="0.127" layer="22"/>
<wire x1="20.32" y1="-26.035" x2="20.955" y2="-25.4" width="0.127" layer="22"/>
<wire x1="20.32" y1="-23.495" x2="20.955" y2="-22.86" width="0.127" layer="22"/>
<wire x1="20.32" y1="-22.225" x2="20.32" y2="-20.955" width="0.127" layer="22"/>
<wire x1="20.32" y1="-24.765" x2="20.32" y2="-23.495" width="0.127" layer="22"/>
<wire x1="25.4" y1="-27.305" x2="25.4" y2="-26.035" width="0.127" layer="22"/>
<wire x1="20.32" y1="-27.305" x2="20.32" y2="-26.035" width="0.127" layer="22"/>
<wire x1="25.4" y1="-23.495" x2="25.4" y2="-24.765" width="0.127" layer="22"/>
<wire x1="25.4" y1="-20.955" x2="25.4" y2="-22.225" width="0.127" layer="22"/>
<wire x1="20.955" y1="-22.86" x2="20.32" y2="-22.225" width="0.127" layer="22"/>
<wire x1="20.955" y1="-25.4" x2="20.32" y2="-24.765" width="0.127" layer="22"/>
<wire x1="25.4" y1="-24.765" x2="24.765" y2="-25.4" width="0.127" layer="22"/>
<wire x1="25.4" y1="-22.225" x2="24.765" y2="-22.86" width="0.127" layer="22"/>
<text x="19.558" y="-25.908" size="0.6096" layer="21" rot="R270">D7</text>
<text x="19.558" y="-23.495" size="0.6096" layer="21" rot="R270">D6</text>
<text x="19.431" y="-20.955" size="0.6096" layer="21" rot="R270">NC</text>
<text x="19.431" y="-18.161" size="0.6096" layer="21" rot="R270">E31</text>
<text x="19.431" y="-15.621" size="0.6096" layer="21" rot="R270">A17</text>
<text x="19.431" y="-13.081" size="0.6096" layer="21" rot="R270">A16</text>
<text x="19.431" y="-10.541" size="0.6096" layer="21" rot="R270">C17</text>
<text x="19.431" y="-8.001" size="0.6096" layer="21" rot="R270">C16</text>
<text x="19.431" y="-5.461" size="0.6096" layer="21" rot="R270">C13</text>
<text x="19.431" y="-2.921" size="0.6096" layer="21" rot="R270">C12</text>
<text x="26.289" y="-20.447" size="0.6096" layer="21" rot="R90" align="bottom-right">AREF</text>
<text x="26.289" y="-23.241" size="0.6096" layer="21" rot="R90" align="bottom-right">D14</text>
<text x="26.289" y="-25.781" size="0.6096" layer="21" rot="R90" align="bottom-right">D15</text>
<text x="22.86" y="19.685" size="0.6096" layer="21" align="bottom-center">&gt;NAME</text>
<wire x1="-26.4" y1="28.8" x2="-26.4" y2="-37.2" width="0.127" layer="51"/>
<wire x1="26.4" y1="29.2" x2="26.4" y2="-37" width="0.127" layer="51"/>
<wire x1="18.2" y1="-45.4" x2="14" y2="-45.4" width="0.127" layer="51"/>
<wire x1="14" y1="-45.4" x2="6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="6" y1="-45.4" x2="-6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-6" y1="-45.4" x2="-14" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-14" y1="-45.4" x2="-18" y2="-45.4" width="0.127" layer="51"/>
<wire x1="18" y1="37.2" x2="-18.2" y2="37.2" width="0.127" layer="51"/>
<wire x1="14" y1="-45.4" x2="14" y2="-47" width="0.127" layer="51"/>
<wire x1="14" y1="-47" x2="6" y2="-47" width="0.127" layer="51"/>
<wire x1="6" y1="-47" x2="6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="-14" y1="-45.4" x2="-14" y2="-47" width="0.127" layer="51"/>
<wire x1="-14" y1="-47" x2="-6" y2="-47" width="0.127" layer="51"/>
<wire x1="-6" y1="-47" x2="-6" y2="-45.4" width="0.127" layer="51"/>
<wire x1="18" y1="37.2" x2="26.4" y2="29" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="-26.4" y1="28.8" x2="-18.2" y2="37.2" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="-18" y1="-45.4" x2="-26.4" y2="-37.2" width="0.127" layer="51" curve="-91.397181"/>
<wire x1="26.4" y1="-37" x2="18.2" y2="-45.4" width="0.127" layer="51" curve="-91.397181"/>
</package>
</packages>
<symbols>
<symbol name="FRDM-KL25Z">
<description>FRDM-KL25Z 
Arduino|KL25Z Pin Names</description>
<text x="-55.88" y="33.02" size="2.032" layer="95">&gt;NAME</text>
<pin name="D7/PTC9" x="53.34" y="-12.7" length="middle" rot="R180"/>
<wire x1="22.86" y1="-10.16" x2="22.86" y2="-50.8" width="0.254" layer="94"/>
<wire x1="22.86" y1="-50.8" x2="48.26" y2="-50.8" width="0.254" layer="94"/>
<wire x1="48.26" y1="-50.8" x2="48.26" y2="-10.16" width="0.254" layer="94"/>
<wire x1="48.26" y1="-10.16" x2="22.86" y2="-10.16" width="0.254" layer="94"/>
<text x="22.86" y="-9.144" size="1.778" layer="97">J1</text>
<pin name="D6/PTC8" x="53.34" y="-17.78" length="middle" rot="R180"/>
<pin name="D5/PTA5" x="53.34" y="-22.86" length="middle" rot="R180"/>
<pin name="D4/PTA4" x="53.34" y="-27.94" length="middle" rot="R180"/>
<pin name="D3/PTA12" x="53.34" y="-33.02" length="middle" rot="R180"/>
<pin name="D2/PTD4" x="53.34" y="-38.1" length="middle" rot="R180"/>
<pin name="D1/PTA2" x="53.34" y="-43.18" length="middle" rot="R180"/>
<pin name="PTC11" x="17.78" y="-12.7" length="middle"/>
<pin name="PTC10" x="17.78" y="-17.78" length="middle"/>
<pin name="PTC5" x="17.78" y="-27.94" length="middle"/>
<pin name="PTC4" x="17.78" y="-33.02" length="middle"/>
<pin name="PTC3" x="17.78" y="-38.1" length="middle"/>
<pin name="PTC0" x="17.78" y="-43.18" length="middle"/>
<pin name="PTC7" x="17.78" y="-48.26" length="middle"/>
<pin name="D0/PTA1" x="53.34" y="-48.26" length="middle" rot="R180"/>
<pin name="PTC6" x="17.78" y="-22.86" length="middle"/>
<wire x1="-55.88" y1="-20.32" x2="-55.88" y2="-50.8" width="0.254" layer="94"/>
<wire x1="-55.88" y1="-50.8" x2="-30.48" y2="-50.8" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-50.8" x2="-30.48" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-20.32" x2="-55.88" y2="-20.32" width="0.254" layer="94"/>
<text x="-55.88" y="-19.558" size="1.778" layer="97">J10</text>
<pin name="PTE20" x="-25.4" y="-22.86" length="middle" rot="R180"/>
<pin name="PTE21" x="-25.4" y="-27.94" length="middle" rot="R180"/>
<pin name="PTE22" x="-25.4" y="-33.02" length="middle" rot="R180"/>
<pin name="PTE23" x="-25.4" y="-38.1" length="middle" rot="R180"/>
<pin name="PTE29" x="-25.4" y="-43.18" length="middle" rot="R180"/>
<pin name="A1/PTB1" x="-60.96" y="-27.94" length="middle"/>
<pin name="A2/PTB2" x="-60.96" y="-33.02" length="middle"/>
<pin name="A3/PTB3" x="-60.96" y="-38.1" length="middle"/>
<pin name="A4/PTC2" x="-60.96" y="-43.18" length="middle"/>
<pin name="A5/PTC1" x="-60.96" y="-48.26" length="middle"/>
<pin name="PTE30" x="-25.4" y="-48.26" length="middle" rot="R180"/>
<pin name="A0/PTB0" x="-60.96" y="-22.86" length="middle"/>
<pin name="AREF" x="53.34" y="35.56" length="middle" rot="R180"/>
<wire x1="22.86" y1="48.26" x2="22.86" y2="-2.54" width="0.254" layer="94"/>
<wire x1="22.86" y1="-2.54" x2="48.26" y2="-2.54" width="0.254" layer="94"/>
<wire x1="48.26" y1="-2.54" x2="48.26" y2="48.26" width="0.254" layer="94"/>
<wire x1="48.26" y1="48.26" x2="22.86" y2="48.26" width="0.254" layer="94"/>
<text x="22.86" y="49.022" size="1.778" layer="97">J2</text>
<pin name="GND2" x="53.34" y="30.48" length="middle" rot="R180"/>
<pin name="D13/PTD1" x="53.34" y="25.4" length="middle" rot="R180"/>
<pin name="D12/PTD3" x="53.34" y="20.32" length="middle" rot="R180"/>
<pin name="D11/PTD2" x="53.34" y="15.24" length="middle" rot="R180"/>
<pin name="D10/PTD0" x="53.34" y="10.16" length="middle" rot="R180"/>
<pin name="D9/PTD5" x="53.34" y="5.08" length="middle" rot="R180"/>
<pin name="NC" x="17.78" y="35.56" length="middle"/>
<pin name="PTE31" x="17.78" y="30.48" length="middle"/>
<pin name="PTA16" x="17.78" y="20.32" length="middle"/>
<pin name="PTC17" x="17.78" y="15.24" length="middle"/>
<pin name="PTC16" x="17.78" y="10.16" length="middle"/>
<pin name="PTC13" x="17.78" y="5.08" length="middle"/>
<pin name="PTC12" x="17.78" y="0" length="middle"/>
<pin name="D8/PTA13" x="53.34" y="0" length="middle" rot="R180"/>
<pin name="PTA17" x="17.78" y="25.4" length="middle"/>
<pin name="SDA/PTE0" x="53.34" y="40.64" length="middle" rot="R180"/>
<pin name="SCL/PTE1" x="53.34" y="45.72" length="middle" rot="R180"/>
<pin name="PTD7" x="17.78" y="45.72" length="middle"/>
<pin name="PTD6" x="17.78" y="40.64" length="middle"/>
<pin name="PTB8" x="-25.4" y="25.4" length="middle" rot="R180"/>
<wire x1="-55.88" y1="27.94" x2="-55.88" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-55.88" y1="-12.7" x2="-30.48" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-12.7" x2="-30.48" y2="27.94" width="0.254" layer="94"/>
<wire x1="-30.48" y1="27.94" x2="-55.88" y2="27.94" width="0.254" layer="94"/>
<text x="-55.88" y="28.702" size="1.778" layer="97">J9</text>
<pin name="PTB9" x="-25.4" y="20.32" length="middle" rot="R180"/>
<pin name="PTB10" x="-25.4" y="15.24" length="middle" rot="R180"/>
<pin name="PTB11" x="-25.4" y="10.16" length="middle" rot="R180"/>
<pin name="PTE2" x="-25.4" y="5.08" length="middle" rot="R180"/>
<pin name="PTE3" x="-25.4" y="0" length="middle" rot="R180"/>
<pin name="PTE4" x="-25.4" y="-5.08" length="middle" rot="R180"/>
<pin name="NC/SDAPTD5" x="-60.96" y="25.4" length="middle"/>
<pin name="IOREF/3V3" x="-60.96" y="20.32" length="middle"/>
<pin name="3V3" x="-60.96" y="10.16" length="middle"/>
<pin name="5V" x="-60.96" y="5.08" length="middle"/>
<pin name="GND1" x="-60.96" y="0" length="middle"/>
<pin name="GND0" x="-60.96" y="-5.08" length="middle"/>
<pin name="VIN" x="-60.96" y="-10.16" length="middle"/>
<pin name="PTE5" x="-25.4" y="-10.16" length="middle" rot="R180"/>
<pin name="RST" x="-60.96" y="15.24" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FRDM-KL25Z" prefix="FRDM" uservalue="yes">
<description>For creating FRDM-KL25Z shields</description>
<gates>
<gate name="G$1" symbol="FRDM-KL25Z" x="-5.08" y="2.54"/>
</gates>
<devices>
<device name="NORMAL" package="FRDM_KL25Z_NORMAL">
<connects>
<connect gate="G$1" pin="3V3" pad="P3V3"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0/PTB0" pad="A0"/>
<connect gate="G$1" pin="A1/PTB1" pad="A1"/>
<connect gate="G$1" pin="A2/PTB2" pad="A2"/>
<connect gate="G$1" pin="A3/PTB3" pad="A3"/>
<connect gate="G$1" pin="A4/PTC2" pad="A4"/>
<connect gate="G$1" pin="A5/PTC1" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D0/PTA1" pad="D0"/>
<connect gate="G$1" pin="D1/PTA2" pad="D1"/>
<connect gate="G$1" pin="D10/PTD0" pad="D10"/>
<connect gate="G$1" pin="D11/PTD2" pad="D11"/>
<connect gate="G$1" pin="D12/PTD3" pad="D12"/>
<connect gate="G$1" pin="D13/PTD1" pad="D13"/>
<connect gate="G$1" pin="D2/PTD4" pad="D2"/>
<connect gate="G$1" pin="D3/PTA12" pad="D3"/>
<connect gate="G$1" pin="D4/PTA4" pad="D4"/>
<connect gate="G$1" pin="D5/PTA5" pad="D5"/>
<connect gate="G$1" pin="D6/PTC8" pad="D6"/>
<connect gate="G$1" pin="D7/PTC9" pad="D7"/>
<connect gate="G$1" pin="D8/PTA13" pad="D8"/>
<connect gate="G$1" pin="D9/PTD5" pad="D9"/>
<connect gate="G$1" pin="GND0" pad="GND0"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="IOREF/3V3" pad="3V3"/>
<connect gate="G$1" pin="NC" pad="NC2"/>
<connect gate="G$1" pin="NC/SDAPTD5" pad="NC1"/>
<connect gate="G$1" pin="PTA16" pad="PTA16"/>
<connect gate="G$1" pin="PTA17" pad="PTA17"/>
<connect gate="G$1" pin="PTB10" pad="PTB10"/>
<connect gate="G$1" pin="PTB11" pad="PTB11"/>
<connect gate="G$1" pin="PTB8" pad="PTB8"/>
<connect gate="G$1" pin="PTB9" pad="PTB9"/>
<connect gate="G$1" pin="PTC0" pad="PTC0"/>
<connect gate="G$1" pin="PTC10" pad="PTC10"/>
<connect gate="G$1" pin="PTC11" pad="PTC11"/>
<connect gate="G$1" pin="PTC12" pad="PTC12"/>
<connect gate="G$1" pin="PTC13" pad="PTC13"/>
<connect gate="G$1" pin="PTC16" pad="PTC16"/>
<connect gate="G$1" pin="PTC17" pad="PTC17"/>
<connect gate="G$1" pin="PTC3" pad="PTC3"/>
<connect gate="G$1" pin="PTC4" pad="PTC4"/>
<connect gate="G$1" pin="PTC5" pad="PTC5"/>
<connect gate="G$1" pin="PTC6" pad="PTC6"/>
<connect gate="G$1" pin="PTC7" pad="PTC7"/>
<connect gate="G$1" pin="PTD6" pad="PTD6"/>
<connect gate="G$1" pin="PTD7" pad="PTD7"/>
<connect gate="G$1" pin="PTE2" pad="PTE2"/>
<connect gate="G$1" pin="PTE20" pad="PTE20"/>
<connect gate="G$1" pin="PTE21" pad="PTE21"/>
<connect gate="G$1" pin="PTE22" pad="PTE22"/>
<connect gate="G$1" pin="PTE23" pad="PTE23"/>
<connect gate="G$1" pin="PTE29" pad="PTE29"/>
<connect gate="G$1" pin="PTE3" pad="PTE3"/>
<connect gate="G$1" pin="PTE30" pad="PTE30"/>
<connect gate="G$1" pin="PTE31" pad="PTE31"/>
<connect gate="G$1" pin="PTE4" pad="PTE4"/>
<connect gate="G$1" pin="PTE5" pad="PTE5"/>
<connect gate="G$1" pin="RST" pad="RESET"/>
<connect gate="G$1" pin="SCL/PTE1" pad="D15"/>
<connect gate="G$1" pin="SDA/PTE0" pad="D14"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="REVERT" package="FRDM_KL25Z_REVERT">
<connects>
<connect gate="G$1" pin="3V3" pad="P3V3"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0/PTB0" pad="A0"/>
<connect gate="G$1" pin="A1/PTB1" pad="A1"/>
<connect gate="G$1" pin="A2/PTB2" pad="A2"/>
<connect gate="G$1" pin="A3/PTB3" pad="A3"/>
<connect gate="G$1" pin="A4/PTC2" pad="A4"/>
<connect gate="G$1" pin="A5/PTC1" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D0/PTA1" pad="D0"/>
<connect gate="G$1" pin="D1/PTA2" pad="D1"/>
<connect gate="G$1" pin="D10/PTD0" pad="D10"/>
<connect gate="G$1" pin="D11/PTD2" pad="D11"/>
<connect gate="G$1" pin="D12/PTD3" pad="D12"/>
<connect gate="G$1" pin="D13/PTD1" pad="D13"/>
<connect gate="G$1" pin="D2/PTD4" pad="D2"/>
<connect gate="G$1" pin="D3/PTA12" pad="D3"/>
<connect gate="G$1" pin="D4/PTA4" pad="D4"/>
<connect gate="G$1" pin="D5/PTA5" pad="D5"/>
<connect gate="G$1" pin="D6/PTC8" pad="D6"/>
<connect gate="G$1" pin="D7/PTC9" pad="D7"/>
<connect gate="G$1" pin="D8/PTA13" pad="D8"/>
<connect gate="G$1" pin="D9/PTD5" pad="D9"/>
<connect gate="G$1" pin="GND0" pad="GND0"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="IOREF/3V3" pad="3V3"/>
<connect gate="G$1" pin="NC" pad="NC2"/>
<connect gate="G$1" pin="NC/SDAPTD5" pad="NC1"/>
<connect gate="G$1" pin="PTA16" pad="PTA16"/>
<connect gate="G$1" pin="PTA17" pad="PTA17"/>
<connect gate="G$1" pin="PTB10" pad="PTB10"/>
<connect gate="G$1" pin="PTB11" pad="PTB11"/>
<connect gate="G$1" pin="PTB8" pad="PTB8"/>
<connect gate="G$1" pin="PTB9" pad="PTB9"/>
<connect gate="G$1" pin="PTC0" pad="PTC0"/>
<connect gate="G$1" pin="PTC10" pad="PTC10"/>
<connect gate="G$1" pin="PTC11" pad="PTC11"/>
<connect gate="G$1" pin="PTC12" pad="PTC12"/>
<connect gate="G$1" pin="PTC13" pad="PTC13"/>
<connect gate="G$1" pin="PTC16" pad="PTC16"/>
<connect gate="G$1" pin="PTC17" pad="PTC17"/>
<connect gate="G$1" pin="PTC3" pad="PTC3"/>
<connect gate="G$1" pin="PTC4" pad="PTC4"/>
<connect gate="G$1" pin="PTC5" pad="PTC5"/>
<connect gate="G$1" pin="PTC6" pad="PTC6"/>
<connect gate="G$1" pin="PTC7" pad="PTC7"/>
<connect gate="G$1" pin="PTD6" pad="PTD6"/>
<connect gate="G$1" pin="PTD7" pad="PTD7"/>
<connect gate="G$1" pin="PTE2" pad="PTE2"/>
<connect gate="G$1" pin="PTE20" pad="PTE20"/>
<connect gate="G$1" pin="PTE21" pad="PTE21"/>
<connect gate="G$1" pin="PTE22" pad="PTE22"/>
<connect gate="G$1" pin="PTE23" pad="PTE23"/>
<connect gate="G$1" pin="PTE29" pad="PTE29"/>
<connect gate="G$1" pin="PTE3" pad="PTE3"/>
<connect gate="G$1" pin="PTE30" pad="PTE30"/>
<connect gate="G$1" pin="PTE31" pad="PTE31"/>
<connect gate="G$1" pin="PTE4" pad="PTE4"/>
<connect gate="G$1" pin="PTE5" pad="PTE5"/>
<connect gate="G$1" pin="RST" pad="RESET"/>
<connect gate="G$1" pin="SCL/PTE1" pad="D15"/>
<connect gate="G$1" pin="SDA/PTE0" pad="D14"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-subd" urn="urn:adsk.eagle:library:189">
<description>&lt;b&gt;SUB-D Connectors&lt;/b&gt;&lt;p&gt;
Harting&lt;br&gt;
NorComp&lt;br&gt;
&lt;p&gt;
PREFIX :&lt;br&gt;
H = High density&lt;br&gt;
F = Female&lt;br&gt;
M = Male&lt;p&gt;
NUMBER: Number of pins&lt;p&gt;
SUFFIX :&lt;br&gt;
H = Horizontal&lt;br&gt;
V = Vertical &lt;br&gt;
P = Shield pin on housing&lt;br&gt;
B = No mounting holes&lt;br&gt;
S = Pins individually placeable (Single)&lt;br&gt;
D = Direct mounting &lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="F09D" urn="urn:adsk.eagle:footprint:10177/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="-8.128" y1="7.239" x2="-7.62" y2="7.747" width="0.1524" layer="21" curve="-90"/>
<wire x1="7.62" y1="7.747" x2="8.128" y2="7.239" width="0.1524" layer="21" curve="-90"/>
<wire x1="-10.414" y1="0.508" x2="-10.414" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="0.508" x2="-10.287" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-10.287" y1="-1.905" x2="-9.652" y2="-2.54" width="0.1524" layer="21" curve="90"/>
<wire x1="-10.287" y1="-1.905" x2="-10.287" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-9.671" y1="-2.54" x2="9.671" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.414" y1="0.508" x2="10.414" y2="1.016" width="0.1524" layer="21"/>
<wire x1="10.287" y1="-1.905" x2="10.287" y2="0.508" width="0.1524" layer="21"/>
<wire x1="10.287" y1="0.508" x2="10.414" y2="0.508" width="0.1524" layer="21"/>
<wire x1="9.652" y1="-2.54" x2="10.287" y2="-1.905" width="0.1524" layer="21" curve="90"/>
<wire x1="-8.128" y1="1.959" x2="-8.128" y2="7.239" width="0.1524" layer="21"/>
<wire x1="-8.763" y1="1.324" x2="-8.128" y2="1.959" width="0.1524" layer="21" curve="90"/>
<wire x1="8.128" y1="1.959" x2="8.128" y2="7.239" width="0.1524" layer="21"/>
<wire x1="8.128" y1="1.959" x2="8.763" y2="1.324" width="0.1524" layer="21" curve="90"/>
<wire x1="-7.62" y1="7.747" x2="7.62" y2="7.747" width="0.1524" layer="21"/>
<wire x1="-16.4592" y1="-2.7432" x2="-15.0876" y2="-4.1148" width="0" layer="48"/>
<wire x1="-15.0876" y1="-4.1148" x2="-13.716" y2="-2.7432" width="0" layer="48"/>
<wire x1="-13.716" y1="-2.7432" x2="-12.3444" y2="-4.1148" width="0" layer="48"/>
<wire x1="-12.3444" y1="-4.1148" x2="-10.9728" y2="-2.7432" width="0" layer="48"/>
<wire x1="10.9728" y1="-2.7432" x2="12.3444" y2="-4.1148" width="0" layer="48"/>
<wire x1="12.3444" y1="-4.1148" x2="13.716" y2="-2.7432" width="0" layer="48"/>
<wire x1="13.716" y1="-2.7432" x2="15.0876" y2="-4.1148" width="0" layer="48"/>
<wire x1="15.0876" y1="-4.1148" x2="16.4592" y2="-2.7432" width="0" layer="48"/>
<wire x1="-17.018" y1="-4.2418" x2="-10.0076" y2="-4.2418" width="0" layer="48"/>
<wire x1="10.922" y1="-4.2418" x2="17.9324" y2="-4.2418" width="0" layer="48"/>
<smd name="1" x="-5.4862" y="-6.0448" dx="1.7" dy="3.5" layer="1"/>
<smd name="2" x="-2.7434" y="-6.0448" dx="1.7" dy="3.5" layer="1"/>
<smd name="3" x="0" y="-6.045" dx="1.7" dy="3.5" layer="1"/>
<smd name="4" x="2.7434" y="-6.0448" dx="1.7" dy="3.5" layer="1"/>
<smd name="5" x="5.4862" y="-6.0448" dx="1.7" dy="3.5" layer="1"/>
<smd name="6" x="-4.1148" y="-6.0452" dx="1.7" dy="3.5" layer="16"/>
<smd name="7" x="-1.3716" y="-6.0452" dx="1.7" dy="3.5" layer="16"/>
<smd name="8" x="1.3716" y="-6.0452" dx="1.7" dy="3.5" layer="16"/>
<smd name="9" x="4.1148" y="-6.0452" dx="1.7" dy="3.5" layer="16"/>
<text x="-8.89" y="-10.16" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="1.27" y="-10.16" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-5.92" y="-2.1786" size="1.27" layer="21" ratio="10">1</text>
<text x="5.085" y="-2.1786" size="1.27" layer="21" ratio="10">5</text>
<text x="4.5418" y="-2.1966" size="1.27" layer="22" ratio="10" rot="MR0">9</text>
<text x="-3.5768" y="-2.1966" size="1.27" layer="22" ratio="10" rot="MR0">6</text>
<text x="11.43" y="-2.54" size="1.27" layer="48">Board</text>
<text x="-7.62" y="5.969" size="1.27" layer="51" ratio="10">F09D</text>
<text x="-16.51" y="-2.54" size="1.27" layer="48">Board </text>
<rectangle x1="-15.494" y1="0.916" x2="15.494" y2="1.424" layer="21"/>
<rectangle x1="-6.0864" y1="-6.56" x2="-4.8864" y2="-4.06" layer="51"/>
<rectangle x1="-4.7148" y1="-6.56" x2="-3.5148" y2="-4.06" layer="52"/>
<rectangle x1="-1.9716" y1="-6.56" x2="-0.7716" y2="-4.06" layer="52"/>
<rectangle x1="0.7716" y1="-6.56" x2="1.9716" y2="-4.06" layer="52"/>
<rectangle x1="-3.3432" y1="-6.56" x2="-2.1432" y2="-4.06" layer="51"/>
<rectangle x1="-0.6" y1="-6.56" x2="0.6" y2="-4.06" layer="51"/>
<rectangle x1="2.1432" y1="-6.56" x2="3.3432" y2="-4.06" layer="51"/>
<rectangle x1="4.8864" y1="-6.56" x2="6.0864" y2="-4.06" layer="51"/>
<rectangle x1="3.5148" y1="-6.56" x2="4.7148" y2="-4.06" layer="52"/>
<rectangle x1="-9.2" y1="-4.16" x2="9.2" y2="-2.56" layer="21"/>
</package>
<package name="F09H" urn="urn:adsk.eagle:footprint:10178/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="-7.62" y1="17.907" x2="-7.366" y2="17.907" width="0.1524" layer="21"/>
<wire x1="-8.128" y1="17.399" x2="-7.62" y2="17.907" width="0.1524" layer="21" curve="-90"/>
<wire x1="7.62" y1="17.907" x2="8.128" y2="17.399" width="0.1524" layer="21" curve="-90"/>
<wire x1="-15.494" y1="7.62" x2="-10.414" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="7.62" x2="-15.494" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="7.62" x2="-15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="10.668" x2="-15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.176" x2="-15.494" y2="11.684" width="0.1524" layer="21"/>
<wire x1="15.494" y1="11.684" x2="15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="15.494" y1="11.176" x2="15.494" y2="10.668" width="0.1524" layer="21"/>
<wire x1="15.494" y1="10.668" x2="15.494" y2="7.62" width="0.1524" layer="21"/>
<wire x1="15.494" y1="7.62" x2="15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.176" x2="-12.954" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-12.954" y1="11.176" x2="-10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="10.668" x2="-10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="10.668" x2="-10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-10.287" y1="8.255" x2="-9.652" y2="7.62" width="0.1524" layer="21" curve="90"/>
<wire x1="-10.414" y1="7.62" x2="-9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="7.62" x2="-9.271" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-10.287" y1="8.255" x2="-10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="7.62" x2="-9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="7.62" x2="9.271" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="6.858" x2="9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="9.271" y1="7.62" x2="9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="9.271" y1="7.62" x2="9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="7.62" x2="10.414" y2="7.62" width="0.1524" layer="21"/>
<wire x1="12.954" y1="11.176" x2="15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="11.176" x2="10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.414" y1="11.176" x2="12.954" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.414" y1="10.668" x2="10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.287" y1="8.255" x2="10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="10.287" y1="10.668" x2="10.414" y2="10.668" width="0.1524" layer="21"/>
<wire x1="9.652" y1="7.62" x2="10.287" y2="8.255" width="0.1524" layer="21" curve="90"/>
<wire x1="-14.859" y1="-3.175" x2="-15.494" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-2.54" x2="-15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-10.033" y1="-3.175" x2="-14.859" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-10.033" y1="-3.175" x2="-9.525" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.667" x2="-9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.667" x2="9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.667" x2="10.033" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="10.033" y1="-3.175" x2="14.986" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="14.986" y1="-3.175" x2="15.494" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="15.494" y1="-2.667" x2="15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.143" x2="0" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-2.7432" y1="-1.143" x2="-2.7432" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-5.4864" y1="-1.143" x2="-5.4864" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-4.1148" y1="1.397" x2="-4.1148" y2="2.413" width="0.8128" layer="51"/>
<wire x1="-1.3716" y1="1.397" x2="-1.3716" y2="2.413" width="0.8128" layer="51"/>
<wire x1="1.3716" y1="1.397" x2="1.3716" y2="2.413" width="0.8128" layer="51"/>
<wire x1="2.7432" y1="-1.143" x2="2.7432" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="4.1148" y1="1.397" x2="4.1148" y2="2.413" width="0.8128" layer="51"/>
<wire x1="5.4864" y1="-1.143" x2="5.4864" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="10.414" y1="7.62" x2="15.494" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.684" x2="-7.747" y2="11.684" width="0.1524" layer="21"/>
<wire x1="-8.128" y1="12.319" x2="-8.128" y2="17.399" width="0.1524" layer="21"/>
<wire x1="-8.763" y1="11.684" x2="-8.128" y2="12.319" width="0.1524" layer="21" curve="90"/>
<wire x1="7.747" y1="11.684" x2="15.494" y2="11.684" width="0.1524" layer="21"/>
<wire x1="8.128" y1="12.319" x2="8.128" y2="17.399" width="0.1524" layer="21"/>
<wire x1="8.128" y1="12.319" x2="8.763" y2="11.684" width="0.1524" layer="21" curve="90"/>
<wire x1="7.747" y1="11.684" x2="-7.747" y2="11.684" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="17.907" x2="7.366" y2="17.907" width="0.1524" layer="21"/>
<wire x1="7.366" y1="17.907" x2="7.62" y2="17.907" width="0.1524" layer="21"/>
<circle x="-12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<circle x="-12.5222" y="0" radius="2.667" width="0" layer="42"/>
<circle x="-12.5222" y="0" radius="2.667" width="0" layer="43"/>
<circle x="12.5222" y="0" radius="2.667" width="0" layer="42"/>
<circle x="12.5222" y="0" radius="2.667" width="0" layer="43"/>
<circle x="12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<pad name="1" x="-5.4864" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-2.7432" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="2.7432" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="5.4864" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-4.1148" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.3716" y="1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="1.3716" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="4.1148" y="1.27" drill="1.016" shape="octagon"/>
<text x="-15.24" y="-6.35" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="13.97" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-7.62" y="-1.905" size="1.27" layer="21" ratio="10">1</text>
<text x="6.985" y="-1.905" size="1.27" layer="21" ratio="10">5</text>
<text x="6.985" y="0.635" size="1.27" layer="21" ratio="10">9</text>
<text x="-7.62" y="0.635" size="1.27" layer="21" ratio="10">6</text>
<text x="14.986" y="2.54" size="1.27" layer="21" ratio="10" rot="R90">2,54</text>
<text x="-7.62" y="8.509" size="1.27" layer="21" ratio="10">F09</text>
<rectangle x1="-9.271" y1="6.858" x2="9.271" y2="7.62" layer="21"/>
<rectangle x1="-15.494" y1="11.176" x2="15.494" y2="11.684" layer="21"/>
<rectangle x1="-5.8928" y1="-0.381" x2="-5.08" y2="6.858" layer="21"/>
<rectangle x1="-4.5212" y1="2.159" x2="-3.7084" y2="6.858" layer="21"/>
<rectangle x1="-3.1496" y1="-0.381" x2="-2.3368" y2="6.858" layer="21"/>
<rectangle x1="-1.778" y1="2.159" x2="-0.9652" y2="6.858" layer="21"/>
<rectangle x1="-0.4064" y1="-0.381" x2="0.4064" y2="6.858" layer="21"/>
<rectangle x1="0.9652" y1="2.159" x2="1.778" y2="6.858" layer="21"/>
<rectangle x1="2.3368" y1="-0.381" x2="3.1496" y2="6.858" layer="21"/>
<rectangle x1="3.7084" y1="2.159" x2="4.5212" y2="6.858" layer="21"/>
<rectangle x1="5.08" y1="-0.381" x2="5.8928" y2="6.858" layer="21"/>
<hole x="-12.5222" y="0" drill="3.302"/>
<hole x="12.5222" y="0" drill="3.302"/>
</package>
<package name="F09HP" urn="urn:adsk.eagle:footprint:10102/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="-7.62" y1="17.907" x2="-7.366" y2="17.907" width="0.1524" layer="21"/>
<wire x1="-8.128" y1="17.399" x2="-7.62" y2="17.907" width="0.1524" layer="21" curve="-90"/>
<wire x1="7.62" y1="17.907" x2="8.128" y2="17.399" width="0.1524" layer="21" curve="-90"/>
<wire x1="-7.747" y1="11.684" x2="7.747" y2="11.684" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="7.62" x2="-10.414" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="7.62" x2="-15.494" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="7.62" x2="-15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="10.668" x2="-15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.176" x2="-15.494" y2="11.684" width="0.1524" layer="21"/>
<wire x1="15.494" y1="11.684" x2="15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="15.494" y1="11.176" x2="15.494" y2="10.668" width="0.1524" layer="21"/>
<wire x1="15.494" y1="10.668" x2="15.494" y2="7.62" width="0.1524" layer="21"/>
<wire x1="15.494" y1="7.62" x2="15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.176" x2="-12.954" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-12.954" y1="11.176" x2="-10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="10.668" x2="-10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="10.668" x2="-10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-10.287" y1="8.255" x2="-9.652" y2="7.62" width="0.1524" layer="21" curve="90"/>
<wire x1="-10.414" y1="7.62" x2="-9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="7.62" x2="-9.271" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-10.287" y1="8.255" x2="-10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="7.62" x2="-9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="7.62" x2="9.271" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="6.858" x2="9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="9.271" y1="7.62" x2="9.271" y2="6.858" width="0.1524" layer="21"/>
<wire x1="9.271" y1="7.62" x2="9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="7.62" x2="10.414" y2="7.62" width="0.1524" layer="21"/>
<wire x1="12.954" y1="11.176" x2="15.494" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="11.176" x2="10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.414" y1="11.176" x2="12.954" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.414" y1="10.668" x2="10.414" y2="11.176" width="0.1524" layer="21"/>
<wire x1="10.287" y1="8.255" x2="10.287" y2="10.668" width="0.1524" layer="21"/>
<wire x1="10.287" y1="10.668" x2="10.414" y2="10.668" width="0.1524" layer="21"/>
<wire x1="9.652" y1="7.62" x2="10.287" y2="8.255" width="0.1524" layer="21" curve="90"/>
<wire x1="-14.859" y1="-3.175" x2="-15.494" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-2.54" x2="-15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-10.033" y1="-3.175" x2="-14.859" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-10.033" y1="-3.175" x2="-9.525" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.667" x2="-9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.667" x2="9.525" y2="7.62" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.667" x2="10.033" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="10.033" y1="-3.175" x2="14.986" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="14.986" y1="-3.175" x2="15.494" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="15.494" y1="-2.667" x2="15.494" y2="7.493" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.143" x2="0" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-2.7432" y1="-1.143" x2="-2.7432" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-5.4864" y1="-1.143" x2="-5.4864" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="-4.1148" y1="1.397" x2="-4.1148" y2="2.413" width="0.8128" layer="51"/>
<wire x1="-1.3716" y1="1.397" x2="-1.3716" y2="2.413" width="0.8128" layer="51"/>
<wire x1="1.3462" y1="1.397" x2="1.3462" y2="2.413" width="0.8128" layer="51"/>
<wire x1="2.7432" y1="-1.143" x2="2.7432" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="4.1148" y1="1.397" x2="4.1148" y2="2.413" width="0.8128" layer="51"/>
<wire x1="5.4864" y1="-1.143" x2="5.4864" y2="-0.127" width="0.8128" layer="51"/>
<wire x1="10.414" y1="7.62" x2="15.494" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="11.684" x2="-7.747" y2="11.684" width="0.1524" layer="21"/>
<wire x1="-8.128" y1="12.319" x2="-8.128" y2="17.399" width="0.1524" layer="21"/>
<wire x1="-8.763" y1="11.684" x2="-8.128" y2="12.319" width="0.1524" layer="21" curve="90"/>
<wire x1="7.747" y1="11.684" x2="15.494" y2="11.684" width="0.1524" layer="21"/>
<wire x1="8.128" y1="12.319" x2="8.128" y2="17.399" width="0.1524" layer="21"/>
<wire x1="8.128" y1="12.319" x2="8.763" y2="11.684" width="0.1524" layer="21" curve="90"/>
<wire x1="-7.366" y1="17.907" x2="7.366" y2="17.907" width="0.1524" layer="21"/>
<wire x1="7.366" y1="17.907" x2="7.62" y2="17.907" width="0.1524" layer="21"/>
<circle x="-12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<circle x="12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<pad name="1" x="-5.4864" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-2.7432" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="2.7432" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="5.4864" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-4.1148" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.3716" y="1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="1.3716" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="4.1148" y="1.27" drill="1.016" shape="octagon"/>
<pad name="G1" x="-12.5222" y="0" drill="3.302" diameter="5.08"/>
<pad name="G2" x="12.5222" y="0" drill="3.302" diameter="5.08"/>
<text x="-15.24" y="-6.35" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="13.97" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-7.62" y="-1.905" size="1.27" layer="21" ratio="10">1</text>
<text x="6.985" y="-1.905" size="1.27" layer="21" ratio="10">5</text>
<text x="6.985" y="0.635" size="1.27" layer="21" ratio="10">9</text>
<text x="-7.62" y="0.635" size="1.27" layer="21" ratio="10">6</text>
<text x="14.986" y="2.54" size="1.27" layer="21" ratio="10" rot="R90">2,54</text>
<text x="-7.62" y="8.509" size="1.27" layer="21" ratio="10">F09</text>
<rectangle x1="-9.271" y1="6.858" x2="9.271" y2="7.62" layer="21"/>
<rectangle x1="-15.494" y1="11.176" x2="15.494" y2="11.684" layer="21"/>
<rectangle x1="-5.8928" y1="-0.381" x2="-5.08" y2="6.858" layer="21"/>
<rectangle x1="-4.5212" y1="2.159" x2="-3.7084" y2="6.858" layer="21"/>
<rectangle x1="-3.1496" y1="-0.381" x2="-2.3368" y2="6.858" layer="21"/>
<rectangle x1="-1.778" y1="2.159" x2="-0.9652" y2="6.858" layer="21"/>
<rectangle x1="-0.4318" y1="-0.381" x2="0.381" y2="6.858" layer="21"/>
<rectangle x1="0.9398" y1="2.159" x2="1.7526" y2="6.858" layer="21"/>
<rectangle x1="2.3368" y1="-0.381" x2="3.1496" y2="6.858" layer="21"/>
<rectangle x1="3.7084" y1="2.159" x2="4.5212" y2="6.858" layer="21"/>
<rectangle x1="5.08" y1="-0.381" x2="5.8928" y2="6.858" layer="21"/>
</package>
<package name="F09V" urn="urn:adsk.eagle:footprint:10179/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="-7.5184" y1="-2.9464" x2="-8.3058" y2="2.3368" width="0.1524" layer="21"/>
<wire x1="6.223" y1="-3.937" x2="7.5317" y2="-2.905" width="0.1524" layer="21" curve="76.489196"/>
<wire x1="6.985" y1="3.937" x2="8.3005" y2="2.3038" width="0.1524" layer="21" curve="-102.298925"/>
<wire x1="8.3058" y1="2.3114" x2="7.5184" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="3.937" x2="6.985" y2="3.937" width="0.1524" layer="21"/>
<wire x1="-8.3051" y1="2.3268" x2="-6.985" y2="3.937" width="0.1524" layer="21" curve="-101.30773"/>
<wire x1="-7.5259" y1="-2.9295" x2="-6.223" y2="-3.937" width="0.1524" layer="21" curve="75.428151"/>
<wire x1="-6.223" y1="-3.937" x2="6.223" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.223" x2="-12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.223" x2="-10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.096" x2="-10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.096" x2="-10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.223" x2="10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-14.859" y1="-6.223" x2="-12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-5.588" x2="-14.859" y2="-6.223" width="0.1524" layer="21" curve="90"/>
<wire x1="14.859" y1="-6.223" x2="15.494" y2="-5.588" width="0.1524" layer="21" curve="90"/>
<wire x1="14.859" y1="6.223" x2="12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="15.494" y1="5.588" x2="15.494" y2="-5.588" width="0.1524" layer="21"/>
<wire x1="14.859" y1="6.223" x2="15.494" y2="5.588" width="0.1524" layer="21" curve="-90"/>
<wire x1="-15.494" y1="5.588" x2="-15.494" y2="-5.588" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="5.588" x2="-14.859" y2="6.223" width="0.1524" layer="21" curve="-90"/>
<wire x1="10.16" y1="-6.223" x2="10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.223" x2="12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.096" x2="12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.096" x2="12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.223" x2="14.859" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.223" x2="10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.223" x2="-10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.096" x2="12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.096" x2="12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.223" x2="10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.223" x2="-12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.223" x2="-14.859" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.096" x2="-10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.096" x2="-10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.223" x2="-12.7" y2="6.223" width="0.1524" layer="21"/>
<circle x="-12.5222" y="0" radius="2.667" width="0" layer="42"/>
<circle x="-12.5222" y="0" radius="2.667" width="0" layer="43"/>
<circle x="12.5222" y="0" radius="2.667" width="0" layer="42"/>
<circle x="12.5222" y="0" radius="2.667" width="0" layer="43"/>
<circle x="1.3716" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="2.7432" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="4.1148" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="5.4864" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="0" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-1.3716" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-2.7432" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-4.1148" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-5.4864" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<circle x="12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<pad name="1" x="5.4864" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="2" x="2.7432" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="3" x="0" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="4" x="-2.7432" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="5" x="-5.4864" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="6" x="4.1148" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="7" x="1.3716" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.3716" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="9" x="-4.1148" y="-1.4224" drill="1.016" shape="octagon"/>
<text x="5.08" y="2.54" size="0.9906" layer="21" ratio="12">1</text>
<text x="2.286" y="2.54" size="0.9906" layer="21" ratio="12">2</text>
<text x="-0.508" y="2.54" size="0.9906" layer="21" ratio="12">3</text>
<text x="-3.175" y="2.54" size="0.9906" layer="21" ratio="12">4</text>
<text x="-5.969" y="2.54" size="0.9906" layer="21" ratio="12">5</text>
<text x="3.81" y="-3.556" size="0.9906" layer="21" ratio="12">6</text>
<text x="1.016" y="-3.556" size="0.9906" layer="21" ratio="12">7</text>
<text x="-1.778" y="-3.556" size="0.9906" layer="21" ratio="12">8</text>
<text x="-4.572" y="-3.556" size="0.9906" layer="21" ratio="12">9</text>
<text x="-15.367" y="6.985" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="6.985" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<hole x="-12.5222" y="0" drill="3.302"/>
<hole x="12.5222" y="0" drill="3.302"/>
</package>
<package name="F09VP" urn="urn:adsk.eagle:footprint:10103/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="-7.5184" y1="-2.9464" x2="-8.3058" y2="2.3368" width="0.1524" layer="21"/>
<wire x1="6.223" y1="-3.937" x2="7.5317" y2="-2.905" width="0.1524" layer="21" curve="76.489196"/>
<wire x1="6.985" y1="3.937" x2="8.3005" y2="2.3038" width="0.1524" layer="21" curve="-102.298925"/>
<wire x1="8.3058" y1="2.3114" x2="7.5184" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="3.937" x2="6.985" y2="3.937" width="0.1524" layer="21"/>
<wire x1="-8.3051" y1="2.3268" x2="-6.985" y2="3.937" width="0.1524" layer="21" curve="-101.30773"/>
<wire x1="-7.5259" y1="-2.9295" x2="-6.223" y2="-3.937" width="0.1524" layer="21" curve="75.428151"/>
<wire x1="-6.223" y1="-3.937" x2="6.223" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.223" x2="-12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.223" x2="-10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.096" x2="-10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.096" x2="-10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.223" x2="10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-14.859" y1="-6.223" x2="-12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-5.588" x2="-14.859" y2="-6.223" width="0.1524" layer="21" curve="90"/>
<wire x1="14.859" y1="-6.223" x2="15.494" y2="-5.588" width="0.1524" layer="21" curve="90"/>
<wire x1="14.859" y1="6.223" x2="12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="15.494" y1="5.588" x2="15.494" y2="-5.588" width="0.1524" layer="21"/>
<wire x1="14.859" y1="6.223" x2="15.494" y2="5.588" width="0.1524" layer="21" curve="-90"/>
<wire x1="-15.494" y1="5.588" x2="-15.494" y2="-5.588" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="5.588" x2="-14.859" y2="6.223" width="0.1524" layer="21" curve="-90"/>
<wire x1="10.16" y1="-6.223" x2="10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.223" x2="12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.096" x2="12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.096" x2="12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.223" x2="14.859" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.223" x2="10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.223" x2="-10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.096" x2="12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.096" x2="12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.223" x2="10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.223" x2="-12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.223" x2="-14.859" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.096" x2="-10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.096" x2="-10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.223" x2="-12.7" y2="6.223" width="0.1524" layer="21"/>
<circle x="1.3716" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="2.7432" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="4.1148" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="5.4864" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="0" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-1.3716" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-2.7432" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-4.1148" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-5.4864" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<circle x="12.5222" y="0" radius="1.651" width="0.1524" layer="21"/>
<pad name="1" x="5.4864" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="2" x="2.7432" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="3" x="0" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="4" x="-2.7432" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="5" x="-5.4864" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="6" x="4.1148" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="7" x="1.3716" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.3716" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="9" x="-4.1148" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="G1" x="-12.5222" y="0" drill="3.302" diameter="5.08"/>
<pad name="G2" x="12.5222" y="0" drill="3.302" diameter="5.08"/>
<text x="5.08" y="2.54" size="0.9906" layer="21" ratio="12">1</text>
<text x="2.286" y="2.54" size="0.9906" layer="21" ratio="12">2</text>
<text x="-0.508" y="2.54" size="0.9906" layer="21" ratio="12">3</text>
<text x="-3.175" y="2.54" size="0.9906" layer="21" ratio="12">4</text>
<text x="-5.969" y="2.54" size="0.9906" layer="21" ratio="12">5</text>
<text x="3.81" y="-3.556" size="0.9906" layer="21" ratio="12">6</text>
<text x="1.016" y="-3.556" size="0.9906" layer="21" ratio="12">7</text>
<text x="-1.778" y="-3.556" size="0.9906" layer="21" ratio="12">8</text>
<text x="-4.572" y="-3.556" size="0.9906" layer="21" ratio="12">9</text>
<text x="-15.367" y="6.985" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="6.985" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="F09VB" urn="urn:adsk.eagle:footprint:10180/1" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<wire x1="7.5184" y1="2.9464" x2="8.3058" y2="-2.3368" width="0.1524" layer="21"/>
<wire x1="-7.5317" y1="2.905" x2="-6.223" y2="3.937" width="0.1524" layer="21" curve="-76.489196"/>
<wire x1="-8.3005" y1="-2.3038" x2="-6.985" y2="-3.937" width="0.1524" layer="21" curve="102.298925"/>
<wire x1="-8.3058" y1="-2.3114" x2="-7.5184" y2="2.921" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-3.937" x2="-6.985" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-3.937" x2="8.3051" y2="-2.3268" width="0.1524" layer="21" curve="101.30773"/>
<wire x1="6.223" y1="3.937" x2="7.5259" y2="2.9295" width="0.1524" layer="21" curve="-75.428151"/>
<wire x1="6.223" y1="3.937" x2="-6.223" y2="3.937" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.223" x2="12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.223" x2="10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="6.096" x2="10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.096" x2="10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="6.223" x2="-10.16" y2="6.223" width="0.1524" layer="21"/>
<wire x1="14.859" y1="6.223" x2="12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="14.859" y1="6.223" x2="15.494" y2="5.588" width="0.1524" layer="21" curve="-90"/>
<wire x1="-15.494" y1="5.588" x2="-14.859" y2="6.223" width="0.1524" layer="21" curve="-90"/>
<wire x1="-14.859" y1="-6.223" x2="-12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-5.588" x2="-15.494" y2="5.588" width="0.1524" layer="21"/>
<wire x1="-15.494" y1="-5.588" x2="-14.859" y2="-6.223" width="0.1524" layer="21" curve="90"/>
<wire x1="15.494" y1="-5.588" x2="15.494" y2="5.588" width="0.1524" layer="21"/>
<wire x1="14.859" y1="-6.223" x2="15.494" y2="-5.588" width="0.1524" layer="21" curve="90"/>
<wire x1="-10.16" y1="6.223" x2="-10.16" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.223" x2="-12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="6.096" x2="-12.7" y2="6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.096" x2="-12.7" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="6.223" x2="-14.859" y2="6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.223" x2="-10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.223" x2="10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-6.096" x2="-12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.096" x2="-12.7" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-6.223" x2="-10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.223" x2="12.7" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.223" x2="14.859" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-6.096" x2="10.16" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.096" x2="10.16" y2="-6.223" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-6.223" x2="12.7" y2="-6.223" width="0.1524" layer="21"/>
<circle x="-1.3716" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-2.7432" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-4.1148" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="-5.4864" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="0" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="1.3716" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="2.7432" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="4.1148" y="1.4224" radius="0.762" width="0.254" layer="51"/>
<circle x="5.4864" y="-1.4224" radius="0.762" width="0.254" layer="51"/>
<pad name="1" x="-5.4864" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="2" x="-2.7432" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="3" x="0" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="4" x="2.7432" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="5" x="5.4864" y="-1.4224" drill="1.016" shape="octagon"/>
<pad name="6" x="-4.1148" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.3716" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="8" x="1.3716" y="1.4224" drill="1.016" shape="octagon"/>
<pad name="9" x="4.1148" y="1.4224" drill="1.016" shape="octagon"/>
<text x="-5.08" y="-2.54" size="0.9906" layer="21" ratio="12" rot="R180">1</text>
<text x="-2.286" y="-2.54" size="0.9906" layer="21" ratio="12" rot="R180">2</text>
<text x="0.508" y="-2.54" size="0.9906" layer="21" ratio="12" rot="R180">3</text>
<text x="3.175" y="-2.54" size="0.9906" layer="21" ratio="12" rot="R180">4</text>
<text x="5.969" y="-2.54" size="0.9906" layer="21" ratio="12" rot="R180">5</text>
<text x="-3.81" y="3.556" size="0.9906" layer="21" ratio="12" rot="R180">6</text>
<text x="-1.016" y="3.556" size="0.9906" layer="21" ratio="12" rot="R180">7</text>
<text x="1.778" y="3.556" size="0.9906" layer="21" ratio="12" rot="R180">8</text>
<text x="4.572" y="3.556" size="0.9906" layer="21" ratio="12" rot="R180">9</text>
<text x="-15.367" y="8.255" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="8.255" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="F09D" urn="urn:adsk.eagle:package:10273/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09D"/>
</packageinstances>
</package3d>
<package3d name="F09H" urn="urn:adsk.eagle:package:10276/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09H"/>
</packageinstances>
</package3d>
<package3d name="F09HP" urn="urn:adsk.eagle:package:10232/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09HP"/>
</packageinstances>
</package3d>
<package3d name="F09V" urn="urn:adsk.eagle:package:10277/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09V"/>
</packageinstances>
</package3d>
<package3d name="F09VP" urn="urn:adsk.eagle:package:10230/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09VP"/>
</packageinstances>
</package3d>
<package3d name="F09VB" urn="urn:adsk.eagle:package:10282/1" type="box" library_version="1">
<description>SUB-D</description>
<packageinstances>
<packageinstance name="F09VB"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="F09" urn="urn:adsk.eagle:symbol:10176/1" library_version="1">
<wire x1="-1.651" y1="3.429" x2="-1.651" y2="1.651" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="1.524" y1="1.651" x2="1.524" y2="3.429" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="-1.651" y1="5.969" x2="-1.651" y2="4.191" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="1.524" y1="-3.429" x2="1.524" y2="-1.651" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="-1.651" y1="0.889" x2="-1.651" y2="-0.889" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="1.524" y1="-0.889" x2="1.524" y2="0.889" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="-1.651" y1="-1.651" x2="-1.651" y2="-3.429" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="1.524" y1="-5.969" x2="1.524" y2="-4.191" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="-1.651" y1="-4.191" x2="-1.651" y2="-5.969" width="0.254" layer="94" curve="180" cap="flat"/>
<wire x1="-4.064" y1="6.9312" x2="-2.5226" y2="8.172" width="0.4064" layer="94" curve="-102.324066" cap="flat"/>
<wire x1="-2.5226" y1="8.1718" x2="3.0654" y2="6.9494" width="0.4064" layer="94"/>
<wire x1="3.0654" y1="6.9495" x2="4.0642" y2="5.7088" width="0.4064" layer="94" curve="-77.655139" cap="flat"/>
<wire x1="4.064" y1="-5.7088" x2="4.064" y2="5.7088" width="0.4064" layer="94"/>
<wire x1="3.0654" y1="-6.9494" x2="4.064" y2="-5.7088" width="0.4064" layer="94" curve="77.657889"/>
<wire x1="-4.064" y1="-6.9312" x2="-4.064" y2="6.9312" width="0.4064" layer="94"/>
<wire x1="-2.5226" y1="-8.1718" x2="3.0654" y2="-6.9494" width="0.4064" layer="94"/>
<wire x1="-4.064" y1="-6.9312" x2="-2.5226" y2="-8.1719" width="0.4064" layer="94" curve="102.337599" cap="flat"/>
<text x="-3.81" y="-10.795" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="8.89" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas"/>
<pin name="6" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="2" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas"/>
<pin name="7" x="7.62" y="0" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="3" x="-7.62" y="0" visible="pad" length="middle" direction="pas"/>
<pin name="8" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="4" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas"/>
<pin name="9" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="5" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="F09" urn="urn:adsk.eagle:component:10379/1" prefix="X" uservalue="yes" library_version="1">
<description>&lt;b&gt;SUB-D&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="F09" x="0" y="0"/>
</gates>
<devices>
<device name="D" package="F09D">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10273/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="H" package="F09H">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10276/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="HP" package="F09HP">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10232/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="V" package="F09V">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10277/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="VP" package="F09VP">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10230/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="VB" package="F09VB">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10282/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ngspice-simulation" urn="urn:adsk.eagle:library:527439">
<description>SPICE compatible library parts</description>
<packages>
</packages>
<symbols>
<symbol name="0" urn="urn:adsk.eagle:symbol:527455/1" library_version="18">
<description>Simulation ground symbol (spice node 0)</description>
<wire x1="-2.54" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<pin name="0" x="0" y="0" visible="off" length="point" direction="sup"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:527478/1" prefix="X_" library_version="18">
<description>Simulation ground symbol (spice node 0)</description>
<gates>
<gate name="G$1" symbol="0" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name="">
<attribute name="SPICEGROUND" value=""/>
<attribute name="_EXTERNAL_" value=""/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC" urn="urn:adsk.eagle:symbol:26928/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" urn="urn:adsk.eagle:component:26957/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
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
<part name="FRDM1" library="FRDM" deviceset="FRDM-KL25Z" device="NORMAL"/>
<part name="X1" library="con-subd" library_urn="urn:adsk.eagle:library:189" deviceset="F09" device="D" package3d_urn="urn:adsk.eagle:package:10273/1"/>
<part name="X_1" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="GND" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRDM1" gate="G$1" x="127" y="-12.7" smashed="yes">
<attribute name="NAME" x="71.12" y="20.32" size="2.032" layer="95"/>
</instance>
<instance part="X1" gate="G$1" x="33.02" y="-43.18" smashed="yes">
<attribute name="VALUE" x="29.21" y="-53.975" size="1.778" layer="96"/>
<attribute name="NAME" x="29.21" y="-34.29" size="1.778" layer="95"/>
</instance>
<instance part="X_1" gate="G$1" x="21.40940625" y="-59.382446875" smashed="yes"/>
<instance part="P+1" gate="VCC" x="45.72" y="-20.32" smashed="yes">
<attribute name="VALUE" x="43.18" y="-22.86" size="1.778" layer="96" rot="R90"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="2"/>
<wire x1="25.4" y1="-40.64" x2="22.86" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-40.64" x2="22.86" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-30.48" x2="109.22" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="FRDM1" gate="G$1" pin="PTE22"/>
<wire x1="109.22" y1="-30.48" x2="109.22" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="109.22" y1="-45.72" x2="101.6" y2="-45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="3"/>
<wire x1="25.4" y1="-43.18" x2="20.32" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-43.18" x2="20.32" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-27.94" x2="111.76" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="111.76" y1="-27.94" x2="111.76" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="FRDM1" gate="G$1" pin="PTE23"/>
<wire x1="111.76" y1="-50.8" x2="101.6" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="0" class="0">
<segment>
<pinref part="X_1" gate="G$1" pin="0"/>
<pinref part="X1" gate="G$1" pin="5"/>
<wire x1="21.40940625" y1="-59.382446875" x2="21.40940625" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="21.40940625" y1="-48.26" x2="25.4" y2="-48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="9"/>
<wire x1="40.64" y1="-48.26" x2="45.72" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="45.72" y1="-48.26" x2="45.72" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>