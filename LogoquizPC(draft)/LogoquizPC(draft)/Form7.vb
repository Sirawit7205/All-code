Public Class Form7

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Close()
    End Sub

    Private Sub Form7_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        TextBox1.Text = My.Settings.hint
        TextBox2.Text = My.Settings.score \ 100
        If TextBox2.Text > 0 Then
            NumericUpDown1.Minimum = 1
            NumericUpDown1.Maximum = TextBox2.Text
        Else
            NumericUpDown1.Enabled = False
            Button2.Enabled = False
        End If
    End Sub

    Private Sub Button6_Click(sender As System.Object, e As System.EventArgs) Handles Button6.Click
        Process.Start("https://www.paypal.com/cgi-bin/webscr?business=lsirawit24@gmail.com&cmd=_xclick&currency_code=USD&amount=0&item_name=Donate%20to%20my%20work%21")
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        My.Settings.hint += NumericUpDown1.Value
        My.Settings.score -= NumericUpDown1.Value * 100
        TextBox1.Text = My.Settings.hint
        TextBox2.Text = My.Settings.score \ 100
        If TextBox2.Text <= 0 Then
            NumericUpDown1.Enabled = False
            Button2.Enabled = False
        End If
    End Sub
End Class